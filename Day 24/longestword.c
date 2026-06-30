#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char longestWord[100] = "";
    char word[100];
    int wIndex = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]s", str);

    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[wIndex++] = str[i];
        } else {
            word[wIndex] = '\0';
            if (strlen(word) > strlen(longestWord)) {
                strcpy(longestWord, word);
            }
            wIndex = 0;
        }
    }

    printf("Longest word: %s\n", longestWord);
    return 0;
}