#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        freq[(int)str[i]]++;
    }

    int found = 0;
    for (int i = 0; i < len; i++) {
        if (freq[(int)str[i]] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No non-repeating character found.\n");

    return 0;
}