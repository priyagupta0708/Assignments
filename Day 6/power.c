#include <stdio.h>

int main()
{
    int x, n, result = 1;

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter power (n): ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        result = result * x;
    }

    printf("%d^%d = %d", x, n, result);

    return 0;
}