#include <stdio.h>

int main() {
    int arr[100], n = 0, choice;

    do {
        printf("\n----- ARRAY OPERATIONS -----\n");
        printf("1. Input Array\n2. Display Array\n3. Find Maximum\n4. Find Minimum\n");
        printf("5. Sum of Elements\n6. Sort Array\n7. Search Element\n8. Reverse Array\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of array: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                break;

            case 2:
                printf("Array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 3: {
                int max = arr[0];
                for (int i = 1; i < n; i++)
                    if (arr[i] > max) max = arr[i];
                printf("Maximum: %d\n", max);
                break;
            }

            case 4: {
                int min = arr[0];
                for (int i = 1; i < n; i++)
                    if (arr[i] < min) min = arr[i];
                printf("Minimum: %d\n", min);
                break;
            }

            case 5: {
                int sum = 0;
                for (int i = 0; i < n; i++)
                    sum += arr[i];
                printf("Sum: %d\n", sum);
                break;
            }

            case 6:
                for (int i = 0; i < n - 1; i++)
                    for (int j = 0; j < n - 1 - i; j++)
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                printf("Array sorted.\n");
                break;

            case 7: {
                int key, found = 0;
                printf("Enter element to search: ");
                scanf("%d", &key);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        printf("Element found at index %d.\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Element not found.\n");
                break;
            }

            case 8:
                for (int i = 0, j = n - 1; i < j; i++, j--) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                printf("Array reversed.\n");
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}