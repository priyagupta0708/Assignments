#include <stdio.h>
#include <string.h>

#define MAX 50

struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Employee emp[MAX];
int count = 0;

void addEmployee() {
    printf("Enter employee ID: ");
    scanf("%d", &emp[count].id);
    printf("Enter name: ");
    scanf(" %[^\n]s", emp[count].name);
    printf("Enter salary: ");
    scanf("%f", &emp[count].salary);
    count++;
    printf("Employee added.\n");
}

void displayEmployees() {
    printf("\nID\tName\tSalary\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%s\t%.2f\n", emp[i].id, emp[i].name, emp[i].salary);
}

float totalSalaryExpense() {
    float total = 0;
    for (int i = 0; i < count; i++)
        total += emp[i].salary;
    return total;
}

void highestPaid() {
    if (count == 0) {
        printf("No employees yet.\n");
        return;
    }
    int idx = 0;
    for (int i = 1; i < count; i++)
        if (emp[i].salary > emp[idx].salary) idx = i;
    printf("Highest paid: %s, Salary: %.2f\n", emp[idx].name, emp[idx].salary);
}

int main() {
    int choice;
    do {
        printf("\n----- MINI EMPLOYEE MANAGEMENT SYSTEM -----\n");
        printf("1. Add Employee\n2. Display All\n3. Total Salary Expense\n4. Highest Paid Employee\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: printf("Total salary expense: %.2f\n", totalSalaryExpense()); break;
            case 4: highestPaid(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}