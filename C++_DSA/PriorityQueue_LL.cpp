#include <iostream>

using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
};

class PriorityQueue
{
    Node *head = nullptr;

public:
    void insert(int data, int priority)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->priority = priority;
            head->next = nullptr;
            return;
        }
        Node *tmp(new Node);
        tmp->data = data;
        tmp->priority = priority;
        tmp->next = head;
        head = tmp;
    }

    void remove()
    {
        int maxPriority(head->priority);
        Node *maxNode(head);
        Node *tmp1(head);

        while (tmp1->next != nullptr)
        {
            if (tmp1->priority >= maxPriority)
            {
                maxPriority = tmp1->priority;
                maxNode = tmp1;
            }
            tmp1 = tmp1->next;
        }

        Node *tmp2(head);

        while (tmp2->next != maxNode)
            tmp2 = tmp2->next;
        tmp2->next = maxNode->next;
        delete maxNode;
    }

    void print()
    {
        Node *tmp(head);
        cout << tmp->data << ' ' << tmp->priority << endl;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            cout << tmp->data << ' ' << tmp->priority << endl;
        }
    }
};

int main()
{
    PriorityQueue q;
    q.insert(176, 99);
    q.insert(14, 3);
    q.insert(157, 999);
    q.insert(1, 33);

    q.print();
    cout << "\nAfter remove max\n";
    q.remove();
    q.print();
}