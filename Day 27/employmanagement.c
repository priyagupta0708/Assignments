#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char designation[30];
    float salary;
};

int main() {
    struct Employee emp[50];
    int n = 0, choice;

    do {
        printf("\n----- EMPLOYEE MANAGEMENT SYSTEM -----\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &emp[n].id);
                printf("Enter name: ");
                scanf(" %[^\n]s", emp[n].name);
                printf("Enter designation: ");
                scanf(" %[^\n]s", emp[n].designation);
                printf("Enter salary: ");
                scanf("%f", &emp[n].salary);
                n++;
                printf("Employee added.\n");
                break;

            case 2:
                printf("\nID\tName\tDesignation\tSalary\n");
                for (int i = 0; i < n; i++)
                    printf("%d\t%s\t%s\t\t%.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                break;

            case 3: {
                int id, found = 0;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (emp[i].id == id) {
                        printf("Found: %s, %s, Salary: %.2f\n", emp[i].name, emp[i].designation, emp[i].salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Employee not found.\n");
                break;
            }

            case 4: {
                int id, found = 0;
                printf("Enter ID to update salary: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (emp[i].id == id) {
                        printf("Enter new salary: ");
                        scanf("%f", &emp[i].salary);
                        found = 1;
                        printf("Salary updated.\n");
                        break;
                    }
                }
                if (!found) printf("Employee not found.\n");
                break;
            }

            case 5: {
                int id, pos = -1;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (emp[i].id == id) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Employee not found.\n");
                } else {
                    for (int i = pos; i < n - 1; i++)
                        emp[i] = emp[i + 1];
                    n--;
                    printf("Employee deleted.\n");
                }
                break;
            }

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}