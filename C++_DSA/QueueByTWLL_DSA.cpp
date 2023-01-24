#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *previous;
};

class QueueTWLL
{
    Node *head = nullptr;
    Node *rear = nullptr;

public:
    void push(int data)
    {
        if (head == nullptr)
        {
            head = new Node;
            rear = head;
            head->previous = head->next = nullptr;
            head->data = data;
        }
        else
        {
            Node *tmp1(head);
            Node *tmp2 = nullptr;
            while (tmp1->previous != nullptr)
            {
                tmp2 = tmp1;
                tmp1 = tmp1->previous;
            }
            tmp1->previous = new Node;
            tmp1 = tmp1->previous;
            head = tmp1;
            tmp1->data = data;
            tmp1->next = tmp2;
            tmp1->previous = nullptr;
        }
    }
    void pop()
    {
        Node *tmp(rear);
        delete tmp;
        rear = rear->previous;
        rear->next = nullptr;
    }
    void print()
    {
        Node *tmp(rear);
        cout << tmp->data << endl;
        while (tmp->previous != nullptr)
        {
            tmp = tmp->previous;
            cout << tmp->data << endl;
        }
    }
};

int main()
{
    QueueTWLL q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    cout << endl
         << "After pop\n"
         << endl;
    q.pop();

    q.print();
}