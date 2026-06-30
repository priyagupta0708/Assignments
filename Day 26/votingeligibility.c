#include <stdio.h>

int main() {
    int age;
    char citizen;

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Are you a citizen? (y/n): ");
    scanf(" %c", &citizen);

    if (age >= 18 && (citizen == 'y' || citizen == 'Y')) {
        printf("You are eligible to vote.\n");
    } else if (age < 18) {
        printf("You are NOT eligible to vote. You need %d more year(s).\n", 18 - age);
    } else {
        printf("You are NOT eligible to vote. Citizenship required.\n");
    }

    return 0;
}