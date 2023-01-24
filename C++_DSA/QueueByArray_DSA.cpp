#include <iostream>

using namespace std;

class Queue
{
    int arr[10];
    int head = -1;
    int rear = 0;

public:
    void push(int data)
    {
        if (head == 9)
        {
            cout << "overflow";
            return;
        }
        arr[++head] = data;
    }
    void pop()
    {
        if (head == -1)
        {
            cout << "underflow";
            return;
        }
        arr[rear++] = -1;
    }

    void print()
    {
        for (int i(rear); i <= head; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Queue q;
    q.push(13);
    q.push(25);
    q.push(343);
    q.push(46);

    q.print();

    q.pop();
    cout << endl
         << "After pop"
         << endl;
    q.print();
}