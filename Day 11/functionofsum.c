#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int x, y, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    result = sum(x, y);  // Function call

    printf("Sum = %d", result);

    return 0;
}