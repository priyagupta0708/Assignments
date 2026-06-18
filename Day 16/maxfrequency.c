#include <stdio.h>

int main()
{
    int arr[5], i, j;
    int maxFreq = 0, element, count;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 5; i++)
    {
        count = 1;

        for(j = i + 1; j < 5; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        if(count > maxFreq)
        {
            maxFreq = count;
            element = arr[i];
        }
    }

    printf("Element with Maximum Frequency = %d\n", element);
    printf("Frequency = %d", maxFreq);

    return 0;
}