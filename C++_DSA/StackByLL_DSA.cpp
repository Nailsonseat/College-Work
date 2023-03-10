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
    s.add(33);
    s.add(456);
    s.add(54);
    s.add(656);

    s.print();

    s.pop();
    cout << endl
         << "After pop" << endl;
    s.print();
}