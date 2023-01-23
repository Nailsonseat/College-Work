#include <iostream>

using namespace std;

class Queue
{
    int arr[10];
    int rear = -1;

public:
    void push(int data)
    {
        if (rear == 9)
        {
            cout << "overflow";
            return;
        }
        arr[++rear] = data;
    }
    void pop()
    {
        if (rear == -1)
        {
            cout << "underflow";
            return;
        }
        arr[rear--] = -1;
    }

    void print()
    {
        for (int i(0); i <= rear; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    q.pop();
    cout << endl
         << endl;
    q.print();
}