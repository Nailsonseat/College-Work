#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class QueueLL
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
            return;
        }
        Node *tmp(new Node);
        tmp->next = head;
        tmp->data = data;
        head = tmp;
    }

    void pop()
    {
        if (head == nullptr)
        {
            cout << "Underflow";
            return;
        }
        Node *tmp1(head);
        Node *tmp2(nullptr);
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
    QueueLL q;
    q.push(1);
    q.push(12);
    q.push(3);
    q.push(16);

    q.print();
    cout << "\n\n";
    q.pop();
    q.print();
}