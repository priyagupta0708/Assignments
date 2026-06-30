#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq[256] = {0};

    printf("Enter first string: ");
    scanf("%[^\n]s", str1);
    getchar();  // clear newline left in buffer
    printf("Enter second string: ");
    scanf("%[^\n]s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        printf("Not an anagram.\n");
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        freq[(int)str1[i]]++;
        freq[(int)str2[i]]--;
    }

    int isAnagram = 1;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram)
        printf("The strings are anagrams.\n");
    else
        printf("The strings are NOT anagrams.\n");

    return 0;
}