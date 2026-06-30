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

    int maxCount = 0;
    char maxChar = str[0];

    for (int i = 0; i < len; i++) {
        if (freq[(int)str[i]] > maxCount) {
            maxCount = freq[(int)str[i]];
            maxChar = str[i];
        }
    }

    printf("Maximum occurring character: %c (count: %d)\n", maxChar, maxCount);
    return 0;
}