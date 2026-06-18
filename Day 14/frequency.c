#include <stdio.h>

int main()
{
    int arr[5], i, key, count = 0;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to find frequency: ");
    scanf("%d", &key);

    for(i = 0; i < 5; i++)
    {
        if(arr[i] == key)
        {
            count++;
        }
    }

    printf("Frequency of %d = %d", key, count);

    return 0;
}