#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0};  // array to store frequency of each ASCII character

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c : %d\n", i, freq[i]);
        }
    }

    return 0;
}