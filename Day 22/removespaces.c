#include <stdio.h>

int main() {
    char str[100];
    int j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    char result[100];
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';  

    printf("String without spaces: %s\n", result);
    return 0;
}