#include <stdio.h>
#include <string.h>

int main() {
    char str[100], result[100];
    int j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        int count = 1;

        while (i + 1 < len && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        result[j++] = str[i];

        if (count > 1) {
            char countStr[10];
            sprintf(countStr, "%d", count);
            for (int k = 0; countStr[k] != '\0'; k++) {
                result[j++] = countStr[k];
            }
        }
    }
    result[j] = '\0';

    printf("Compressed string: %s\n", result);
    return 0;
}