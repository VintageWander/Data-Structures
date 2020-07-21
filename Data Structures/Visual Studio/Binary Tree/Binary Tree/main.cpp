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
		for (int i = 0; i < vector.size(); ++i)
		{
			if ((2 * i + 1) < vector.size() && (2 * i + 2) < vector.size())
			{
				if (vector[i] == NULL && vector[2 * i + 1] != NULL && vector[2 * i + 2] != NULL)
				{
					std::cout << "Invalid Tree" << std::endl;
					return;
				}
			}
		}
		std::vector<Node*> nodePointers;
		for (int i = 0; i < vector.size(); ++i)
		{
			nodePointers.emplace_back(new Node(vector[i]));
			++size;
		}
		root = nodePointers[0];
		for (int i = 0; i < vector.size() / 2; ++i)
		{
			if (nodePointers[i] != NULL)
			{
				if ((2 * i + 1) < vector.size() && nodePointers[2 * i + 1] != NULL)
				{
					nodePointers[i]->left = nodePointers[2 * i + 1];
				}
				if ((2 * i + 2) < vector.size() && nodePointers[2 * i + 2] != NULL)
				{
					nodePointers[i]->right = nodePointers[2 * i + 2];
				}
			}
		}
	}
	void Print()
	{
		if (root == NULL)
		{
			std::cout << "There are nothing to print" << std::endl;
			return;
		}
		std::vector<Node*> nodePointers;
		nodePointers.emplace_back(root);
		for (int i = 0; i < size; ++i)
		{
			if (nodePointers[i]->data == NULL)
			{
				std::cout << "null ";
			}
			else
			{
				std::cout << nodePointers[i]->data << " ";
			}
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
		if (root == NULL)
		{
			std::cout << "There are nothing to clear" << std::endl;
			return;
		}
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
	std::vector<int> vector{ 2, 4, 6, NULL, 8, 10, 12, NULL, NULL, 14, NULL, NULL, NULL, NULL, 32, NULL, NULL, NULL, NULL, 20, 22  };
	BinaryTree* bt = new BinaryTree();
	bt->VectorToBT(vector);
	bt->Print(); 
	bt->Clear();
	delete bt;
	// just updated the code to process NULL values in the vector to create binary tree
}