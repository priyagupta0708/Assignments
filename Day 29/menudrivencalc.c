#include <stdio.h>

int main() {
    int choice;
    double a, b, result;

    do {
        printf("\n----- CALCULATOR -----\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
        }

        switch (choice) {
            case 1:
                printf("Result: %.2lf\n", a + b);
                break;
            case 2:
                printf("Result: %.2lf\n", a - b);
                break;
            case 3:
                printf("Result: %.2lf\n", a * b);
                break;
            case 4:
                if (b == 0)
                    printf("Error: Division by zero.\n");
                else
                    printf("Result: %.2lf\n", a / b);
                break;
            case 5:
                if ((int)b == 0)
                    printf("Error: Division by zero.\n");
                else
                    printf("Result: %d\n", (int)a % (int)b);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}