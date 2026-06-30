#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];  
    float total;
    float percentage;
    char grade;
};

void calculateResult(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++)
        s->total += s->marks[i];

    s->percentage = s->total / 5;

    if (s->percentage >= 90) s->grade = 'A';
    else if (s->percentage >= 75) s->grade = 'B';
    else if (s->percentage >= 60) s->grade = 'C';
    else if (s->percentage >= 40) s->grade = 'D';
    else s->grade = 'F';
}

int main() {
    struct Student s;

    printf("----- MARKSHEET GENERATION SYSTEM -----\n");
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf(" %[^\n]s", s.name);

    char *subjects[5] = {"Physics", "Chemistry", "Maths", "English", "Computer Science"};

    for (int i = 0; i < 5; i++) {
        printf("Enter marks in %s (out of 100): ", subjects[i]);
        scanf("%f", &s.marks[i]);
    }

    calculateResult(&s);

    printf("\n========= MARKSHEET =========\n");
    printf("Roll No: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("------------------------------\n");
    for (int i = 0; i < 5; i++)
        printf("%-20s: %.2f\n", subjects[i], s.marks[i]);
    printf("------------------------------\n");
    printf("Total: %.2f / 500\n", s.total);
    printf("Percentage: %.2f%%\n", s.percentage);
    printf("Grade: %c\n", s.grade);
    printf("Result: %s\n", (s.grade == 'F') ? "FAIL" : "PASS");
    printf("==============================\n");

    return 0;
}