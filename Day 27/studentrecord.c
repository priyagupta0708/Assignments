#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student students[50];
    int n = 0, choice;

    do {
        printf("\n----- STUDENT RECORD SYSTEM -----\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &students[n].roll);
                printf("Enter name: ");
                scanf(" %[^\n]s", students[n].name);
                printf("Enter marks: ");
                scanf("%f", &students[n].marks);
                n++;
                printf("Student added.\n");
                break;

            case 2:
                printf("\nRoll\tName\tMarks\n");
                for (int i = 0; i < n; i++)
                    printf("%d\t%s\t%.2f\n", students[i].roll, students[i].name, students[i].marks);
                break;

            case 3: {
                int roll, found = 0;
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                for (int i = 0; i < n; i++) {
                    if (students[i].roll == roll) {
                        printf("Found: %s, Marks: %.2f\n", students[i].name, students[i].marks);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student not found.\n");
                break;
            }

            case 4: {
                int roll, pos = -1;
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                for (int i = 0; i < n; i++) {
                    if (students[i].roll == roll) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Student not found.\n");
                } else {
                    for (int i = pos; i < n - 1; i++)
                        students[i] = students[i + 1];
                    n--;
                    printf("Student deleted.\n");
                }
                break;
            }

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}