#include <stdio.h>

int main()
{
    int i, j;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            printf("And of %d %d : %d\n", i, j, i && j);
        }

    printf("\n\n");

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            printf("Or of %d %d : %d\n", i, j, i || j);
        }
}