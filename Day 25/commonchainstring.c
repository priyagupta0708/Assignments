#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};

    printf("Enter first string: ");
    scanf("%[^\n]s", str1);
    getchar();
    printf("Enter second string: ");
    scanf("%[^\n]s", str2);

    for (int i = 0; str1[i] != '\0'; i++)
        freq1[(int)str1[i]]++;

    for (int i = 0; str2[i] != '\0'; i++)
        freq2[(int)str2[i]]++;

    printf("Common characters: ");
    for (int i = 0; i < 256; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            int count = (freq1[i] < freq2[i]) ? freq1[i] : freq2[i];
            for (int c = 0; c < count; c++)
                printf("%c ", i);
        }
    }
    printf("\n");

    return 0;
}