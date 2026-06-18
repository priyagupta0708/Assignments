#include <stdio.h>

int main()
{
    int a[2][2], b[2][2], sub[2][2];
    int i, j;

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Subtraction Matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }

    return 0;
}