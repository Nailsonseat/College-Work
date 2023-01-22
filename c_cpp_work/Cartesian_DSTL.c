#include <stdio.h>

int main()
{
    int size, i, j;
    int A[1000];
    int B[1000];
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < size; i++)
    {
        scanf("%d", &B[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("{%d,%d}\n", A[i], B[j]);
        }
    }
}