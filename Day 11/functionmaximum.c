#include <stdio.h>
int maximum(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int x, y, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    max = maximum(x, y);  // Function call

    printf("Maximum number = %d", max);

    return 0;
}