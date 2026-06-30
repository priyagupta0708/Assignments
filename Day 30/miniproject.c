#include <stdio.h>
#include <string.h>

// ---------- Array functions ----------
void inputArray(int arr[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// ---------- String functions ----------
void reverseString(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i]) return 0;
    return 1;
}

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
            ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            count++;
    }
    return count;
}

// ---------- Main menu ----------
int main() {
    int choice;
    int arr[100], n;
    char str[100];

    do {
        printf("\n===== MINI PROJECT MENU =====\n");
        printf("1. Array: Input, Display, Find Max\n");
        printf("2. Array: Sort\n");
        printf("3. String: Reverse\n");
        printf("4. String: Check Palindrome\n");
        printf("5. String: Count Vowels\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter array size: ");
                scanf("%d", &n);
                inputArray(arr, n);
                displayArray(arr, n);
                printf("Maximum element: %d\n", findMax(arr, n));
                break;

            case 2:
                bubbleSort(arr, n);
                printf("Sorted ");
                displayArray(arr, n);
                break;

            case 3:
                printf("Enter a string: ");
                scanf(" %[^\n]s", str);
                reverseString(str);
                printf("Reversed: %s\n", str);
                break;

            case 4:
                printf("Enter a string: ");
                scanf(" %[^\n]s", str);
                printf("%s\n", isPalindrome(str) ? "Palindrome" : "Not a Palindrome");
                break;

            case 5:
                printf("Enter a string: ");
                scanf(" %[^\n]s", str);
                printf("Vowel count: %d\n", countVowels(str));
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}