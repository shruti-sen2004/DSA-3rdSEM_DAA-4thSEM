//Write a C program to implement 8 Queen Problem.

#include <stdio.h>
#include <stdlib.h>

#define N 8

int board[N][N];

void printBoard() {
    int i;
    int j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i;
    int j;
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return 0;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return 0;
    }
    return 1;
}

int solveNQUtil(int col) {
    if (col >= N)
        return 1;
    int i;
    for (i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

void solveNQ() {
    if (solveNQUtil(0)) {
        printBoard();
    } else {
        printf("Solution does not exist.\n");
    }
}

int main() {
    solveNQ();
    return 0;
}
