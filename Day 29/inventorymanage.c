#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Item items[50];
    int n = 0, choice;

    do {
        printf("\n----- INVENTORY MANAGEMENT SYSTEM -----\n");
        printf("1. Add Item\n2. Display All Items\n3. Search Item\n");
        printf("4. Update Quantity\n5. Delete Item\n6. Show Total Inventory Value\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &items[n].id);
                printf("Enter item name: ");
                scanf(" %[^\n]s", items[n].name);
                printf("Enter quantity: ");
                scanf("%d", &items[n].quantity);
                printf("Enter price per unit: ");
                scanf("%f", &items[n].price);
                n++;
                printf("Item added.\n");
                break;

            case 2:
                printf("\nID\tName\tQty\tPrice\n");
                for (int i = 0; i < n; i++)
                    printf("%d\t%s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
                break;

            case 3: {
                int id, found = 0;
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (items[i].id == id) {
                        printf("Found: %s, Qty: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Item not found.\n");
                break;
            }

            case 4: {
                int id, found = 0;
                printf("Enter item ID to update: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (items[i].id == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &items[i].quantity);
                        found = 1;
                        printf("Quantity updated.\n");
                        break;
                    }
                }
                if (!found) printf("Item not found.\n");
                break;
            }

            case 5: {
                int id, pos = -1;
                printf("Enter item ID to delete: ");
                scanf("%d", &id);
                for (int i = 0; i < n; i++) {
                    if (items[i].id == id) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Item not found.\n");
                } else {
                    for (int i = pos; i < n - 1; i++)
                        items[i] = items[i + 1];
                    n--;
                    printf("Item deleted.\n");
                }
                break;
            }

            case 6: {
                float total = 0;
                for (int i = 0; i < n; i++)
                    total += items[i].quantity * items[i].price;
                printf("Total inventory value: %.2f\n", total);
                break;
            }

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}