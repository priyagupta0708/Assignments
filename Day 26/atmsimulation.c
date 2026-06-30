#include <stdio.h>

int main() {
    float balance = 5000.0;  
    int choice;
    float amount;
    int correctPin = 1234, pin;

    printf("Enter your 4-digit PIN: ");
    scanf("%d", &pin);

    if (pin != correctPin) {
        printf("Incorrect PIN. Exiting.\n");
        return 0;
    }

    do {
        printf("\n----- ATM MENU -----\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                printf("Deposit successful. New balance: %.2f\n", balance);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > balance)
                    printf("Insufficient balance.\n");
                else {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}