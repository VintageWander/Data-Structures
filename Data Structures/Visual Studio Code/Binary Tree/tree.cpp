#include <iostream>
#include <string>
#include <vector>

struct Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node() 
    { 
        this->data = 0; 
        this->left = NULL; 
        this->right = NULL; 
    }
    Node(const int& d)      
    { 
        this->data = d; 
        this->left = NULL; 
        this->right = NULL;
    }
};

class BinaryTree
{
private:
    Node* root;
    int size;
public:
    BinaryTree()
    {
        this->root = NULL;
        this->size = 0;
    }
    void VectToTree(const std::vector<int>& vector)
    {
        for (int i = 0; i < vector.size(); i++)
        {
            if ((2 * i + 2) < vector.size())
            {
                if (vector[i] == NULL && vector[2 * i + 1] != NULL && vector[2 * i + 2] != NULL)
                {
                    std::cout << "Invalid tree\n";
                    return;
                }
            }
        }
        std::vector<Node*> nodePointers;
        for (int i = 0; i < vector.size(); i++)
        {
            nodePointers.emplace_back(new Node(vector[i]));
            ++size;
        }
        root = nodePointers[0];
        for (int i = 0; i < vector.size() / 2; i++)
        {
            if (2 * i + 1 < vector.size() && nodePointers[2 * i + 1] != NULL) nodePointers[i]->left = nodePointers[2 * i + 1];
            if (2 * i + 2 < vector.size() && nodePointers[2 * i + 2] != NULL) nodePointers[i]->right = nodePointers[2 * i + 2];
        }
    }
    void ClearTree()
    {
        if (size == 0 || root == NULL)
        { 
            std::cout << "There are nothing to clear\n";
            return;
        }
        std::vector<Node*> nodePointers;
        nodePointers.emplace_back(root);
        for (int i = 0; i < size; i++)
        {
            if (nodePointers[i]->left != NULL)  nodePointers.emplace_back(nodePointers[i]->left);
            if (nodePointers[i]->right != NULL) nodePointers.emplace_back(nodePointers[i]->right);
            delete nodePointers[i];
        }
        root = NULL;
        size = 0;
    }
    void Print()
    {
        if (size == 0 || root == NULL)
        {
            std::cout << "There are nothing to display\n";
            return;
        }
        std::vector<Node*> nodePointers;
        nodePointers.emplace_back(root);
        for (int i = 0; i < size; i++)
        {
            std::cout << nodePointers[i]->data << " ";
            if (nodePointers[i]->left != NULL)  nodePointers.emplace_back(nodePointers[i]->left);
            if (nodePointers[i]->right != NULL) nodePointers.emplace_back(nodePointers[i]->right);
        }
        std::cout << "\n";
    }
};

int main() 
{
    std::vector<int> vector {1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,23};
    BinaryTree* bt = new BinaryTree();
    bt->VectToTree(vector);
    bt->Print();
    bt->ClearTree();
    bt->Print();
    delete bt;
};