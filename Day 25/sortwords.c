#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char words[50][50];
    int wordCount = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]s", str);

    char *token = strtok(str, " ");
    while (token != NULL) {
        strcpy(words[wordCount++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - 1 - i; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                char temp[50];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("Words sorted by length:\n");
    for (int i = 0; i < wordCount; i++)
        printf("%s\n", words[i]);

    return 0;
}