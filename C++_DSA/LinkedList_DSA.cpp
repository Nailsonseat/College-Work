#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
	Node *head = nullptr;

public:
	void push(int data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node *tmp1(head);
			while (tmp1->next != nullptr)
			{
				tmp1 = tmp1->next;
			}
			tmp1->next = new Node;
			tmp1 = tmp1->next;
			tmp1->data = data;
			tmp1->next = nullptr;
		}
	}
	void del(int data)
	{
		if (head->data == data)
		{
			Node *tmp(head);
			head = head->next;
			delete tmp;
			return;
		}
		else
		{
			Node *tmp1(head);
			Node *tmp2(nullptr);
			while (tmp1->next != nullptr)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next;
				if (data == tmp1->data)
				{
					tmp2->next = tmp1->next;
					delete tmp1;
					return;
				}
			}
		}
	}
	void print()
	{
		Node *tmp(head);
		cout << tmp->data << endl;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
			cout << tmp->data << endl;
		}
	}
};

int main()
{
	LinkedList l;
	l.push(1);
	l.push(2);
	l.push(4);
	l.push(5);

	l.print();
	cout << endl
		 << endl;

	l.del(4);
	l.print();
}