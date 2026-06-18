#include <stdio.h>

int main()
{
    int arr1[5], arr2[5], i, j, found;

    printf("Enter 5 elements of first array:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 5 elements of second array:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Union of arrays:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }

    for(i = 0; i < 5; i++)
    {
        found = 0;

        for(j = 0; j < 5; j++)
        {
            if(arr2[i] == arr1[j])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            printf("%d ", arr2[i]);
        }
    }

    return 0;
}