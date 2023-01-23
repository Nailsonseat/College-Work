#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularQueue
{
    Node *head = nullptr;

public:
    void push(int data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = head;
        }
        else
        {
            Node *tmp1(head);
            while (tmp1->next != head)
            {
                tmp1 = tmp1->next;
            }
            tmp1->next = new Node;
            tmp1 = tmp1->next;
            tmp1->data = data;
            tmp1->next = head;
        }
    }

    void pop()
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *tmp1(head);
            Node *tmp2(nullptr);

            while (tmp1->next != head)
            {
                tmp2 = tmp1;
                tmp1 = tmp1->next;
            }
            delete tmp1;
            tmp2->next = head;
        }
    }
    void print()
    {
        Node *tmp(head);
        cout << tmp->data << endl;
        while (tmp->next != head)
        {
            tmp = tmp->next;
            cout << tmp->data << endl;
        }
    }
};

int main()
{
    CircularQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    q.print();
    cout << endl
         << endl;
    q.pop();
    q.print();
}