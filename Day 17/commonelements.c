#include <stdio.h>

int main()
{
    int arr1[5], arr2[5];
    int i, j;

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

    printf("Common elements are:\n");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }

    return 0;
}