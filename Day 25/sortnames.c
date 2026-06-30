#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();

    char names[n][50];
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%[^\n]s", names[i]), getchar();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[50];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    return 0;
}