#include <stdio.h>
#include <string.h>

void naiveStringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int found = 0;

    // Remove newline characters if any
    if (text[n - 1] == '\n') text[n - 1] = '\0';
    if (pattern[m - 1] == '\n') pattern[m - 1] = '\0';

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found in the text.\n");
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    naiveStringMatch(text, pattern);

    return 0;
}
 

