#include <stdlib.h>

int isPresent(int x[], int size, int target)
{
    for (int i = 0; i < size; i++)
        if (x[i] == target)
            return 1;
    return 0;
}

void SymDiff(int a[], int x, int b[], int y)
{
    int size = 0;
    int final[x + y];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (a[i] == b[j] && !isPresent(final, size, a[i]))
            {
                final[size++] = a[i];
            }
        }
    }

    printf("Symetric Difference\n");

    for (int i = 0; i < x; i++)
    {
        if (isPresent(final, size, a[i]) == 0)
        {
            printf("%d ", a[i]);
        }
    }

    for (int i = 0; i < y; i++)
    {
        if (isPresent(final, size, b[i]) == 0)
        {
            printf("%d ", b[i]);
        }
    }
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
    SymDiff(A, x, B, y);
}
