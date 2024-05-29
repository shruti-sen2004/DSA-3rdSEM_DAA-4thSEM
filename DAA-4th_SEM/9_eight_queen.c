//METHOD1` : GIVES ALL POSSIBLE SOLUTIONS

// #include <stdio.h>
// #include <stdlib.h>

// int board[20], count;

// int main(){
//     int n;
//     printf("ENTER THE NUMBER OF QUEENS: ");
//     scanf("%d",&n);
//     nqueen(1,n);
//     return 0;
// }

// int place(int row, int column){
//     int i;
//     for(i = 1; i <= row-1; i++){
//         if(board[i] == column){
//             return 0;
//         }
//         else{
//             if(abs(board[i] - column) == abs(i - row)){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

// void nqueen(int row, int n){
//     int column;
//     for(column = 1; column <= n; column++){
//         if(place(row,column)){
//             board[row] = column;
//             if(row == n){
//                 printf(n);
//             }
//             else{
//                 nqueen(row+1,n);
//             }
//         }
//     }
// }

// void print(int n){
//     int i, j;
//     printf("\n\nSOLUTION %d:\n\n",++count);
//     for(i = 1; i <= n; i++){
//         printf("\t%d",i);
//     }
//     for(i = 1; i <= n; i++){
//         printf("\n\n%d",i);
//         for(j = 1; j <= n; j++){
//             if(board[i] == j){
//                 printf("\tQ");
//             }
//             else{
//                 printf("\t-");
//             }
//         }
//     }
// }

//METHOD 2 : GIVES ONLY ONE OPTIMAL SOLUTION

#include <stdio.h>
#include <stdlib.h>

#define N 4

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
