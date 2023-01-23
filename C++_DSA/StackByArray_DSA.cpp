#include <iostream>

using namespace std;

class Stack
{
    int arr[10];
    int size = 0;

public:
    void push(int item)
    {
        if (size == 10)
        {
            cout << "overflow";
        }
        arr[size++] = item;
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Underflow";
        }
        arr[--size] = -1;
    }
    void print()
    {
        for (int i(0); i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(9);
    s.push(51);
    s.push(3);

    s.print();
    s.pop();

    s.print();
}