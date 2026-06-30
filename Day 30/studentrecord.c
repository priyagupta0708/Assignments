#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int roll;
    char name[50];
    char grade;
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    printf("Enter roll number: ");
    scanf("%d", &students[count].roll);
    printf("Enter name: ");
    scanf(" %[^\n]s", students[count].name);
    printf("Enter marks: ");
    scanf("%f", &students[count].marks);

    if (students[count].marks >= 90) students[count].grade = 'A';
    else if (students[count].marks >= 75) students[count].grade = 'B';
    else if (students[count].marks >= 60) students[count].grade = 'C';
    else students[count].grade = 'D';

    count++;
    printf("Student added.\n");
}

void displayAll() {
    printf("\nRoll\tName\tMarks\tGrade\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%s\t%.2f\t%c\n", students[i].roll, students[i].name, students[i].marks, students[i].grade);
}

void searchStudent() {
    int roll, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Found: %s, Marks: %.2f, Grade: %c\n", students[i].name, students[i].marks, students[i].grade);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found.\n");
}

void sortByMarks() {
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
    printf("Sorted by marks (highest first).\n");
}

int main() {
    int choice;
    do {
        printf("\n----- STUDENT RECORD SYSTEM -----\n");
        printf("1. Add Student\n2. Display All\n3. Search by Roll\n4. Sort by Marks\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: sortByMarks(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}