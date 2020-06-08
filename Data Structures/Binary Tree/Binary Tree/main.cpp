#include <iostream>
#include <vector>

struct Node 
{
	int data;
	Node* left;
	Node* right;
	Node()
	{
		this->data = NULL;
		this->left = NULL;
		this->right = NULL;
	}
	Node(const int& data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinaryTree 
{
public:
	Node* root;
	int size;
	BinaryTree()
	{
		this->root = NULL;
		this->size = 0;
	}
	void VectorToBT(std::vector<int> &vector)
	{
		std::vector<Node*> nodePointers;
		for (int i = 0; i < vector.size(); ++i)
		{
			nodePointers.emplace_back(new Node(vector[i]));
			++size;
		}
		root = nodePointers[0];
		for (int i = 0; i < vector.size() / 2; ++i)
		{
			if ((2 * i + 1) < vector.size())
			{
				nodePointers[i]->left = nodePointers[2 * i + 1];
			}
			if ((2 * i + 2) < vector.size())
			{
				nodePointers[i]->right = nodePointers[2 * i + 2];
			}
		}
	}
	void Print()
	{
		std::vector<Node*> nodePointers;
		nodePointers.emplace_back(root);
		for (int i = 0; i < size; ++i)
		{
			std::cout << nodePointers[i]->data << " ";
			if (nodePointers[i]->left != NULL)
			{
				nodePointers.emplace_back(nodePointers[i]->left);
			}
			if (nodePointers[i]->right != NULL)
			{
				nodePointers.emplace_back(nodePointers[i]->right);
			}
		}
	}
	void Clear()
	{
		std::vector<Node*> nodePointers;
		nodePointers.emplace_back(root);
		for (int i = 0; i < size; ++i)
		{
			if (nodePointers[i]->left != NULL)
			{
				nodePointers.emplace_back(nodePointers[i]->left);
			}
			if (nodePointers[i]->right != NULL)
			{
				nodePointers.emplace_back(nodePointers[i]->right);
			}
			delete nodePointers[i];
		}
		size = 0;
	}
};

int main() 
{
	std::vector<int> vector{ 1, 6, 10, 11, 22, 23, 25, 28, 29, 33, 38, 40, 41, 42, 52, 54, 56, 59, 62, 71, 74, 82, 84, 90, 93, 95, 96, 97 };
	BinaryTree* bt = new BinaryTree();
	bt->VectorToBT(vector);
	bt->Print();
	bt->Clear();
	delete bt;
}