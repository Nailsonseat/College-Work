#include <iostream>

using namespace std;

void lsearch(int *arr, int item)
{
    for (int i(0); i < 10; i++)
    {
        if (item == arr[i])
        {
            cout << "(Linear Search) Element found at position " << i + 1 << endl;
            break;
        }
    }
}

void bsearch(int *arr, int lb, int ub, int item)
{
    if (lb > ub)
    {
        return;
    }
    else
    {
        int mid((ub + lb) / 2);
        if (item < arr[mid])
            bsearch(arr, lb, mid - 1, item);
        else if (item > arr[mid])
            bsearch(arr, mid + 1, ub, item);
        else
            cout << "(Binary Search) Element found at position " << mid + 1 << endl;
    }
}

int main()
{
    int arr[] = {6, 25, 9, 32, 36, 50, 31, 14, 19, 3};
    lsearch(arr, 32);
    bsearch(arr, 0, 9, 32);
}