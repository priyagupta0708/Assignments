#include <stdio.h>

int main() {
    int n, i;
    long long a = 0, b = 1, c;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n == 1)
        printf("Nth Fibonacci term = %lld\n", a);
    else if (n == 2)
        printf("Nth Fibonacci term = %lld\n", b);
    else {
        for (i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        printf("Nth Fibonacci term = %lld\n", b);
    }

    return 0;
}