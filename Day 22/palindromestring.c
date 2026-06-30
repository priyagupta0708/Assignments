#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}