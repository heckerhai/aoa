/* C program to solve the N-Queens Problem using Backtracking */

#include <stdio.h>
#include <stdbool.h>

#define N 4   // Number of queens and size of the board

/* ---------------------- PRINT BOARD ---------------------- */
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

/* ---------------------- CHECK SAFETY ---------------------- */
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check left side of the current row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower-left diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* ---------------------- SOLVE USING BACKTRACKING ---------------------- */
bool solveNQUtil(int board[N][N], int col) {
    // Base case: all queens are placed
    if (col >= N)
        return true;

    // Try placing queen in all rows of this column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place queen

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false; // No safe position found
}

/* ---------------------- MAIN SOLVER FUNCTION ---------------------- */
bool solveNQ() {
    int board[N][N] = { {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} };

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}

/* ---------------------- MAIN FUNCTION ---------------------- */
int main() {
    solveNQ();
    return 0;
}
