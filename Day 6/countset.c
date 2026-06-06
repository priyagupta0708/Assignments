#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);  // Removes the rightmost set bit
        count++;
    }
    return count;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Number of set bits = %d\n", countSetBits(num));

    return 0;
}