#include <stdio.h>

int main()
{
    int arr[4], i;
    int sum = 0, total = 0, missing;

    printf("Enter 4 elements (from 1 to 5):\n");

    for(i = 0; i < 4; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    total = 5 * (5 + 1) / 2;

    missing = total - sum;

    printf("Missing Number = %d", missing);

    return 0;
}