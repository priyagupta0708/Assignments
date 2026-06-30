#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    struct Contact contacts[50];
    int n = 0, choice;

    do {
        printf("\n----- CONTACT MANAGEMENT SYSTEM -----\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]s", contacts[n].name);
                printf("Enter phone number: ");
                scanf(" %[^\n]s", contacts[n].phone);
                printf("Enter email: ");
                scanf(" %[^\n]s", contacts[n].email);
                n++;
                printf("Contact added.\n");
                break;

            case 2:
                printf("\nName\tPhone\tEmail\n");
                for (int i = 0; i < n; i++)
                    printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
                break;

            case 3: {
                char name[50];
                int found = 0;
                printf("Enter name to search: ");
                scanf(" %[^\n]s", name);
                for (int i = 0; i < n; i++) {
                    if (strcmp(contacts[i].name, name) == 0) {
                        printf("Found: %s, %s, %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Contact not found.\n");
                break;
            }

            case 4: {
                char name[50];
                int pos = -1;
                printf("Enter name to delete: ");
                scanf(" %[^\n]s", name);
                for (int i = 0; i < n; i++) {
                    if (strcmp(contacts[i].name, name) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Contact not found.\n");
                } else {
                    for (int i = pos; i < n - 1; i++)
                        contacts[i] = contacts[i + 1];
                    n--;
                    printf("Contact deleted.\n");
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