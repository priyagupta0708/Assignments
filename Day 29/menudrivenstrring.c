#include <stdio.h>
#include <string.h>

int main() {
    char str[100], str2[100];
    int choice;

    do {
        printf("\n----- STRING OPERATIONS -----\n");
        printf("1. Find Length\n2. Reverse String\n3. Check Palindrome\n4. Convert to Uppercase\n");
        printf("5. Convert to Lowercase\n6. Concatenate Another String\n7. Count Vowels\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 7) {
            printf("Enter a string: ");
            scanf(" %[^\n]s", str);
        }

        switch (choice) {
            case 1:
                printf("Length: %lu\n", strlen(str));
                break;

            case 2: {
                int i, j;
                for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
                printf("Reversed: %s\n", str);
                break;
            }

            case 3: {
                int len = strlen(str), isPalin = 1;
                for (int i = 0; i < len / 2; i++) {
                    if (str[i] != str[len - 1 - i]) {
                        isPalin = 0;
                        break;
                    }
                }
                printf("%s\n", isPalin ? "Palindrome" : "Not a Palindrome");
                break;
            }

            case 4:
                for (int i = 0; str[i] != '\0'; i++)
                    if (str[i] >= 'a' && str[i] <= 'z')
                        str[i] -= 32;
                printf("Uppercase: %s\n", str);
                break;

            case 5:
                for (int i = 0; str[i] != '\0'; i++)
                    if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] += 32;
                printf("Lowercase: %s\n", str);
                break;

            case 6:
                printf("Enter second string: ");
                scanf(" %[^\n]s", str2);
                strcat(str, str2);
                printf("Concatenated: %s\n", str);
                break;

            case 7: {
                int vowels = 0;
                for (int i = 0; str[i] != '\0'; i++) {
                    char ch = str[i];
                    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                        ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
                        vowels++;
                }
                printf("Vowel count: %d\n", vowels);
                break;
            }

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}