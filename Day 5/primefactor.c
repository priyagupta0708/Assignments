#include <stdio.h>

int main() {
    int n, i, largestPrimeFactor = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++) {
        while(n % i == 0) {
            largestPrimeFactor = i;
            n = n / i;
        }
    }

    printf("Largest Prime Factor = %d", largestPrimeFactor);

    return 0;
}