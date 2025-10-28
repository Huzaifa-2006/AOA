#include <stdio.h>

int sum = 0;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int w[10] = {2, 20, 20, 30, 40, 30, 60, 10};
    int p[10] = {15, 100, 90, 60, 40, 15, 10, 1};
    int m = 102;  // maximum weight capacity
    int n = 8;    // number of items
    int v[10][105], x[10];
    int i, j;

    printf("\nItem No.\tProfit\tWeight\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\n", i + 1, p[i], w[i]);
    }

    // Initialize first row and column
    for (i = 0; i <= m; i++)
        v[0][i] = 0;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (j >= w[i - 1])
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + p[i - 1]);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    // Initialize x array
    for (i = 0; i < n; i++)
        x[i] = 0;

    // Backtrack to find which items were selected
    i = n;
    j = m;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i - 1] = 1;
            j = j - w[i - 1];
        }
        i--;
    }

    printf("\nOptimal set of items:\n");
    for (i = 0; i < n; i++) {
        printf("X%d = %d\t", i + 1, x[i]);
        if (x[i] == 1)
            sum += p[i];
    }

    printf("\n\nTotal Profit = %d\n", sum);

    return 0;
}


