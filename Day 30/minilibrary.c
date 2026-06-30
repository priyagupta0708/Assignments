#include <stdio.h>
#include <string.h>

#define MAX 50

struct Book {
    int id;
    char title[50];
    int available;
};

struct Book books[MAX];
int count = 0;

void addBook() {
    printf("Enter book ID: ");
    scanf("%d", &books[count].id);
    printf("Enter title: ");
    scanf(" %[^\n]s", books[count].title);
    books[count].available = 1;
    count++;
    printf("Book added.\n");
}

void displayBooks() {
    printf("\nID\tTitle\tStatus\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%s\t%s\n", books[i].id, books[i].title, books[i].available ? "Available" : "Issued");
}

int findBookIndex(int id) {
    for (int i = 0; i < count; i++)
        if (books[i].id == id) return i;
    return -1;
}

void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    int idx = findBookIndex(id);
    if (idx == -1) printf("Book not found.\n");
    else if (!books[idx].available) printf("Book already issued.\n");
    else {
        books[idx].available = 0;
        printf("Book issued.\n");
    }
}

void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    int idx = findBookIndex(id);
    if (idx == -1) printf("Book not found.\n");
    else if (books[idx].available) printf("Book wasn't issued.\n");
    else {
        books[idx].available = 1;
        printf("Book returned.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n----- MINI LIBRARY SYSTEM -----\n");
        printf("1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}