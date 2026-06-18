#include <stdio.h>

int main()
{
    int arr1[5], arr2[5], arr3[10];
    int i;

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

    for(i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i];
    }

    for(i = 0; i < 5; i++)
    {
        arr3[i + 5] = arr2[i];
    }

    printf("Merged Array:\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}