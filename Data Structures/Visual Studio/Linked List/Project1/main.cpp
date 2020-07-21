#include <iostream>
#include <vector>

struct Node 
{
	int data;
	Node* next;
	Node* prev;

	Node()
	{
		this->data = NULL;
		this->next = NULL;
		this->prev = NULL;
	}

	Node(const int& data)
	{
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}

	Node(const int& data, Node* next, Node* prev)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

class DoublyLinkedList
{
public:
	Node* head;
	Node* tail;
	int size;

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	Node* CreateList(std::vector<int>& list)
	{
		for (int i = 0; i < list.size(); ++i)
		{
			if (head == NULL)
			{
				Node* temp;
				temp = new Node(list[i]);
				temp->next = NULL;
				temp->prev = NULL;
				head = temp;
				tail = temp;
				++size;
			}
			else
			{
				Node* temp;
				temp = new Node(list[i]);
				temp->next = NULL;
				temp->prev = tail;
				tail->next = temp;
				tail = tail->next;
				++size;
			}
		}
		return head;
	}
	void InsertBack(const int& data)
	{
		if (head == NULL)
		{
			Node* temp;
			temp = new Node(data);
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
			++size;
		}
		else
		{
			Node* temp;
			temp = new Node(data);
			temp->next = NULL;
			temp->prev = tail;
			tail->next = temp;
			tail = tail->next;
			++size;
		}
	}
	void InsertFront(const int& data)
	{
		if (head == NULL)
		{
			Node* temp;
			temp = new Node(data);
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
			++size;
		}
		else
		{
			Node* temp;
			temp = new Node(data);
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = head->prev;
			++size;
		}
	}
	void Print()
	{
		Node* search;
		search = head;
		if (head == NULL)
		{
			std::cout << "There are nothing to be printed here " << std::endl;
			return;
		}
		while(search != NULL)
		{
			std::cout << search->data << " ";
			search = search->next;
		}
		std::cout << std::endl;
		return;
	}
	void ClearList()
	{
		Node* destroyer;
		destroyer = head;
		head = head->next;
		while (true)
		{
			if (head == NULL)
			{
				delete destroyer;
				destroyer = NULL;
				head = NULL;
				break;
			}
			delete destroyer;
			destroyer = head;
			head = head->next;
		}
	}
};

int main()
{
	std::vector<int> list{ 1, 2, 4, 6, 8, 10, 12, 15 };
	DoublyLinkedList* dll = new DoublyLinkedList();
	dll->CreateList(list);
	dll->Print();
	dll->ClearList();
	delete dll;
	return 0;
};