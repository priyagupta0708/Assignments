#include <stdio.h>

int main()
{
    int arr[5], i;
    int even = 0, odd = 0;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 5; i++)
    {
        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Number of Even Elements = %d\n", even);
    printf("Number of Odd Elements = %d", odd);

    return 0;
}