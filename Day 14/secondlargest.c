#include <stdio.h>

int main()
{
    int arr[5], i;
    int largest, secondLargest;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    largest = secondLargest = arr[0];

    for(i = 1; i < 5; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    printf("Second Largest Element = %d", secondLargest);

    return 0;
}