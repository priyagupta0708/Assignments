#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;   // 0 = available, 1 = issued
};

int main() {
    struct Book books[50];
    int n = 0, choice;

    do {
        printf("\n----- LIBRARY MANAGEMENT SYSTEM -----\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book by Title\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &books[n].id);
                printf("Enter title: ");
                scanf(" %[^\n]s", books[n].title);
                printf("Enter author: ");
                scanf(" %[^\n]s", books[n].author);
                books[n].isIssued = 0;
                n++;
                printf("Book added.\n");
                break;

            case 2:
                printf("\nID\tTitle\tAuthor\tStatus\n");
                for (int i = 0; i < n; i++)
                    printf("%d\t%s\t%s\t%s\n", books[i].id, books[i].title, books[i].author,
                           books[i].isIssued ? "Issued" : "Available");
                break;

            case 3: {
                int id, found = 0;
                printf("Enter book ID to issue: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (books[i].id == id) {
                        found = 1;
                        if (books[i].isIssued)
                            printf("Book already issued.\n");
                        else {
                            books[i].isIssued = 1;
                            printf("Book issued successfully.\n");
                        }
                        break;
                    }
                }
                if (!found) printf("Book not found.\n");
                break;
            }

            case 4: {
                int id, found = 0;
                printf("Enter book ID to return: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (books[i].id == id) {
                        found = 1;
                        if (!books[i].isIssued)
                            printf("Book was not issued.\n");
                        else {
                            books[i].isIssued = 0;
                            printf("Book returned successfully.\n");
                        }
                        break;
                    }
                }
                if (!found) printf("Book not found.\n");
                break;
            }

            case 5: {
                char title[50];
                int found = 0;
                printf("Enter title to search: ");
                scanf(" %[^\n]s", title);
                for (int i = 0; i < n; i++) {
                    if (strcmp(books[i].title, title) == 0) {
                        printf("Found: %s by %s, Status: %s\n", books[i].title, books[i].author,
                               books[i].isIssued ? "Issued" : "Available");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Book not found.\n");
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