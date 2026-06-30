#include <stdio.h>
#include <string.h>

int main() {
    char str[100], result[100];
    int seen[256] = {0};
    int j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (seen[(int)str[i]] == 0) {
            seen[(int)str[i]] = 1;
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    printf("String after removing duplicates: %s\n", result);
    return 0;
}