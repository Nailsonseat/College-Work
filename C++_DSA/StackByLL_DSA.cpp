#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int data;
};

class Stack
{
    Node *head = nullptr;
    int size = 0;

public:
    void add(int data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node *tmp(head);
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node;
            tmp = tmp->next;
            tmp->data = data;
            tmp->next = nullptr;
        }
        size++;
    }

    void pop()
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *tmp1 = head;
        Node *tmp2 = nullptr;
        while (tmp1->next != nullptr)
        {
            tmp2 = tmp1;
            tmp1 = tmp1->next;
        }
        delete tmp1;
        tmp2->next = nullptr;
    }

    void print()
    {
        Node *tmp(head);
        while (tmp->next != nullptr)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
        cout << tmp->data << endl;
    }
};

int main()
{
    Stack s;
    s.add(3);
    s.add(4);
    s.add(5);
    s.add(6);

    s.print();

    s.pop();
    cout << endl
         << endl;
    s.print();
}