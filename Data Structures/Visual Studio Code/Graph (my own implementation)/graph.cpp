#include <iostream>
#include <vector>

struct Node
{
    int data = 0;
    std::vector<Node*> connections;
    Node()
    {
        this->data = 0;
        this->connections;
    }
    Node(int data)
    {
        this->data = data;
        this->connections;
    }
    Node(int data, Node node)
    {
        this->data = data;
        this->connections.emplace_back(&node);
    }
    ~Node()
    {
        this->data = 0;
        this->connections.clear();
    }
};

class Graph
{
    std::vector<Node*> nodePointers;
    void recursiveDFS(Node node, std::vector<int>& visited)
    {
        int i = 0;
        for (i = 0; i < visited.size(); i++)
        {
            if (visited[i] == node.data)
            {
                return;
            }
        }
        std::cout << node.data << " ";
        visited.emplace_back(node.data);
        if (node.connections.size() <= 1 && visited.size() >= 1) {std::cout << visited[i - 1] << " "; return;}
        for (int i = 0; i < node.connections.size(); i++)
        {
            recursiveDFS(*node.connections[i], visited);
        }
    }
    int nodeToIndex(int data)
    {
        if (nodePointers.size() <= 0) {std::cout << "The graph is empty\n"; return -1;}
        bool manipulated = false;
        for (int i = 0; i < nodePointers.size(); i++)
        {
            if (nodePointers[i]->data == data)
            {
                return i;
            }
        }
        if (!manipulated)
        {
            std::cout << "Can't find the node from the data\n";
            return -1;
        }
        return -1;
    }
public:
    void addVertex(int data)
    {
        nodePointers.emplace_back(new Node(data));
    }
    void addConnection(int first, int second)
    {
        int first_index = nodeToIndex(first);
        int second_index = nodeToIndex(second);
        nodePointers[first_index]->connections.emplace_back(nodePointers[second_index]);
    }
    void getConnection(int data)
    {
        if (nodePointers.size() == 0)
        {
            std::cout << "There are nothing to search\n";
            return;
        }
        int foundIndex = nodeToIndex(data);
        std::cout << nodePointers[foundIndex]->data << " connects to : ";
        if (nodePointers[foundIndex]->connections.size() == 0)
        {
            return;
        }
        else
        {
            for (int i = 0; i < nodePointers[foundIndex]->connections.size(); i++)
            {
                std::cout << nodePointers[foundIndex]->connections[i]->data << " ";
            }
        }
    }

    void bfs(int data)
    {
        if (nodePointers.size() <= 0)
        {
            std::cout << "The graph is empty\n";
            return;
        }
        else
        {
            int foundIndex = nodeToIndex(data);
            int loopIndex = 0;
            std::vector<std::pair<Node*, bool>> pair_nodePointers;
            for (int i = 0; i < nodePointers.size(); i++)
            {
                pair_nodePointers.emplace_back(std::make_pair(nodePointers[i], false));
            }
            std::vector<Node*> bfsQueue;
            bfsQueue.emplace_back(nodePointers[foundIndex]);
            pair_nodePointers[foundIndex].second = true;
            while (bfsQueue.size() < nodePointers.size())
            {
                if (bfsQueue[loopIndex]->connections.size())
                {
                    for (int i = 0; i < bfsQueue[loopIndex]->connections.size(); i++)
                    {
                        int index = nodeToIndex(bfsQueue[loopIndex]->connections[i]->data);
                        if (pair_nodePointers[index].second == false)
                        {
                            bfsQueue.emplace_back(bfsQueue[loopIndex]->connections[i]);
                            pair_nodePointers[index].second = true;
                        }
                    }
                }
                ++loopIndex;
            }
            for (int i = 0; i < bfsQueue.size(); i++)
            {
                std::cout << bfsQueue[i]->data << " ";
            }   
        }
        std::cout << "\n"; 
    }

    void dfs(int data)
    {
        if (nodePointers.size() <= 0)
        {
            std::cout << "The graph is empty\n";
            return;
        }
        else
        {
            int foundIndex = nodeToIndex(data);
            std::vector<int> visited;
            recursiveDFS(*nodePointers[foundIndex], visited);
        }
        std::cout << "\n"; 
    }
    void Print()
    {
        if (nodePointers.size() <= 0)
        {
            std::cout << "There are nothing to print\n";
            return;
        }
        else
        {
            for (int i = 0 ; i < nodePointers.size(); i++)
            {
                if (nodePointers[i] != nullptr) std::cout << nodePointers[i]->data << " ";
            }
        }
        std::cout << "\n";    
    }
    void Clear()
    {
        if (nodePointers.size() <= 0)
        {
            std::cout << "There are nothing to clear\n";
            return;
        }
        else
        {
            std::vector<Node*> tempVector;
            for (int i = 0; i < nodePointers.size(); i++)
            {
                tempVector.emplace_back(nodePointers[i]);
            }
            nodePointers.clear();
            std::cout << "\n";
        }
    }
};

int main()
{
    auto gp = new Graph();
    gp->addVertex(1);
    gp->addVertex(2);
    gp->addVertex(3);
    gp->addVertex(4);
    gp->addVertex(5);
    gp->addVertex(6);
    gp->addVertex(7);
    gp->addVertex(8);

    gp->addConnection(1,2);
    gp->addConnection(1,7);

    gp->addConnection(2,3);
    gp->addConnection(2,7);

    gp->addConnection(3,2);
    gp->addConnection(3,4);

    gp->addConnection(4,3);
    gp->addConnection(4,5);
    gp->addConnection(4,6);

    gp->addConnection(5,4);

    gp->addConnection(6,4);
    gp->addConnection(6,7);

    gp->addConnection(7,1);
    gp->addConnection(7,2);
    gp->addConnection(7,6);
    gp->addConnection(7,8);

    gp->dfs(1);

    gp->bfs(4);

    gp->Print();
    gp->Clear();
    gp->Print();
    delete gp;
    return 0;
}