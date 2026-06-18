#include <stdio.h>

int main()
{
    int arr[5], i, j = 0, temp;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 5; i++)
    {
        if(arr[i] != 0)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }

    printf("Array after moving zeroes to end:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
