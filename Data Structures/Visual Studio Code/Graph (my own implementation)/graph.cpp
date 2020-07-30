#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

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
public:
    void addVertex(int data)
    {
        nodePointers.emplace_back(new Node(data));
    }
    void addConnection(int first, int second)
    {
        int first_index = 0;
        bool manipulated1 = false; 
        for(int i = 0; i < nodePointers.size(); i++)
        {
            if (nodePointers[i]->data == first)
            {
                first_index = i;
                manipulated1 = true;
                break;
            } 
        }
        if (!manipulated1)
        {
            std::cout << "First vertex not found\n";
            return;
        }
        int second_index = 0;
        bool manipulated2 = false;
        for (int i = 0; i < nodePointers.size(); i++)
        {
            if (nodePointers[i]->data == second)
            {
                second_index = i;
                manipulated2 = true;
                break;
            }
        }
        if (!manipulated2)
        {
            std::cout << "Second vertex not found\n";
            return;
        }
        nodePointers[first_index]->connections.emplace_back(nodePointers[second_index]);
    }
    void getConnection(int data)
    {
        if (nodePointers.size() == 0)
        {
            std::cout << "There are nothing to search\n";
            return;
        }
        int index = 0;
        bool manipulated = false;
        for (int i = 0; i < nodePointers.size(); i++)
        {
            if(nodePointers[i]->data == data)
            {
                index = i;
                manipulated = true;
                break;
            }
        }
        if (!manipulated)
        {
            std::cout << "Can't find the data\n";
            return;
        }
        std::cout << nodePointers[index]->data << " connects to : ";
        if (nodePointers[index]->connections.size() == 0)
        {
            return;
        }
        else
        {
            for (int i = 0; i < nodePointers[index]->connections.size(); i++)
            {
                std::cout << nodePointers[index]->connections[i]->data << " ";
            }
        }
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
            int index = 0;
            bool manipulated = false;
            for (int i = 0; i < nodePointers.size(); i++)
            {
                if (nodePointers[i]->data == data)
                {
                    index = i;
                    manipulated = true;
                    break;
                }
            }
            if (!manipulated)
            {
                std::cout << "Can't find the node\n";
                return;
            }
            std::vector<int> visited;
            recursiveDFS(*nodePointers[index], visited);
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
            std::cout << "There are nothing to print\n";
            return;
        }
        else
        {
            for (int i = 0; i < nodePointers.size(); i++)
            {
                delete nodePointers[i];
                nodePointers[i] = nullptr;
            }
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

    gp->Print();
    gp->Clear();
    gp->Print();
    delete gp;
    return 0;
}