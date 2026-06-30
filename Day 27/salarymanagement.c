#include <stdio.h>
#include <string.h>

struct SalaryRecord {
    int empId;
    char name[50];
    float basic;
    float hra;
    float da;
    float deductions;
    float netSalary;
};

void calculateSalary(struct SalaryRecord *e) {
    // simple calculation rules
    e->hra = e->basic * 0.40;       // 40% of basic
    e->da = e->basic * 0.20;        // 20% of basic
    e->deductions = e->basic * 0.10; // 10% deduction (PF etc.)
    e->netSalary = e->basic + e->hra + e->da - e->deductions;
}

int main() {
    struct SalaryRecord emp[50];
    int n = 0, choice;

    do {
        printf("\n----- SALARY MANAGEMENT SYSTEM -----\n");
        printf("1. Add Employee Salary Record\n");
        printf("2. Display Salary Slip (all)\n");
        printf("3. Search by Employee ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &emp[n].empId);
                printf("Enter name: ");
                scanf(" %[^\n]s", emp[n].name);
                printf("Enter basic salary: ");
                scanf("%f", &emp[n].basic);
                calculateSalary(&emp[n]);
                n++;
                printf("Record added.\n");
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    printf("\n--- Salary Slip ---\n");
                    printf("ID: %d\nName: %s\n", emp[i].empId, emp[i].name);
                    printf("Basic: %.2f\nHRA: %.2f\nDA: %.2f\nDeductions: %.2f\n",
                           emp[i].basic, emp[i].hra, emp[i].da, emp[i].deductions);
                    printf("Net Salary: %.2f\n", emp[i].netSalary);
                }
                break;

            case 3: {
                int id, found = 0;
                printf("Enter employee ID: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (emp[i].empId == id) {
                        printf("Name: %s, Net Salary: %.2f\n", emp[i].name, emp[i].netSalary);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Employee not found.\n");
                break;
            }

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}