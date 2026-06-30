#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account accounts[50];
    int n = 0, choice;

    do {
        printf("\n----- BANK ACCOUNT SYSTEM -----\n");
        printf("1. Open Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accounts[n].accNo);
                printf("Enter name: ");
                scanf(" %[^\n]s", accounts[n].name);
                printf("Enter initial deposit: ");
                scanf("%f", &accounts[n].balance);
                n++;
                printf("Account created successfully.\n");
                break;

            case 2: {
                int accNo, found = 0;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accNo);
                for (int i = 0; i < n; i++) {
                    if (accounts[i].accNo == accNo) {
                        found = 1;
                        printf("Enter amount to deposit: ");
                        scanf("%f", &amount);
                        accounts[i].balance += amount;
                        printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
                        break;
                    }
                }
                if (!found) printf("Account not found.\n");
                break;
            }

            case 3: {
                int accNo, found = 0;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accNo);
                for (int i = 0; i < n; i++) {
                    if (accounts[i].accNo == accNo) {
                        found = 1;
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &amount);
                        if (amount > accounts[i].balance)
                            printf("Insufficient balance.\n");
                        else {
                            accounts[i].balance -= amount;
                            printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
                        }
                        break;
                    }
                }
                if (!found) printf("Account not found.\n");
                break;
            }

            case 4: {
                int accNo, found = 0;
                printf("Enter account number: ");
                scanf("%d", &accNo);
                for (int i = 0; i < n; i++) {
                    if (accounts[i].accNo == accNo) {
                        printf("Balance: %.2f\n", accounts[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account not found.\n");
                break;
            }

            case 5:
                printf("\nAcc No\tName\tBalance\n");
                for (int i = 0; i < n; i++)
                    printf("%d\t%s\t%.2f\n", accounts[i].accNo, accounts[i].name, accounts[i].balance);
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