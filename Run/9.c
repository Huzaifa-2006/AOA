#include <stdio.h>
#include <stdlib.h>  // ? Added this for abs()
#include <math.h>

int count = 0;
int board[20];

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solveNQueens(int row, int n) {
    if (row == n) {
        count++;
        printf("Solution %d:\n", count);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf(board[i] == j ? " Q " : " . ");
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n = 8;  // Solve for 8 queens

    solveNQueens(0, n);
    printf("Total solutions for %d-Queens = %d\n", n, count);

    return 0;
}

