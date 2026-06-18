#include <stdio.h>

int main()
{
    int arr[5], i, temp;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    temp = arr[0];

    for(i = 0; i < 4; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[4] = temp;

    printf("Array after left rotation:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}