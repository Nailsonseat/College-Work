#include <stdlib.h>

int isPresent(int x[], int size, int target)
{
    for (int i = 0; i < size; i++)
        if (x[i] == target)
            return 1;
    return 0;
}

void Union(int a[], int x, int b[], int y)
{
    int size = 0;
    int final[x + y];

    for (int i = 0; i < x; i++)
    {
        if (isPresent(final, size, a[i]) == 0)
        {
            final[size] = a[i];
            size++;
        }
    }

    for (int i = 0; i < y; i++)
    {
        if (isPresent(final, size, b[i]) == 0)
        {
            final[size] = b[i];
            size++;
        }
    }

    printf("Union\n");

    for (int i = 0; i < size; i++)
        printf("%d ", final[i]);
}

int main()
{

    int x, y;
    printf("Enter size of both arrays (x y)\n");
    scanf("%d %d", &x, &y);
    int A[x], B[y];
    printf("Enter first array\n");
    for (int i = 0; i < x; i++)
        scanf("%d", &A[i]);
    printf("Enter second array\n");
    for (int i = 0; i < y; i++)
        scanf("%d", &B[i]);
    Union(A, x, B, y);
}