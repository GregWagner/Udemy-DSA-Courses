#include <iostream>

bool validSpot(int n, int board[][20], int x, int y) {
    // check columns
    for (int k {}; k < x; ++k) {
        if (board[k][y]) {
            return false;
        }
    }

    // check left diagonal
    int i { x };
    int j { y };
    while (i >= 0 && j >= 0) {
        if (board[i][j]) {
            return false;
        }
        --i;
        --j;
    }

    // right diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n) {
        if (board[i][j]) {
            return false;
        }
        --i;
        ++j;
    }
    return true;
}

int countSolveNQueen(int n, int board[][20], int row = 0) {
    // base case
    if (row == n) {
        return 1;
    }

    // recursive case - try to place a queen in every row
    int count {};
    for (int col {}; col < n; ++col) {
        if (validSpot(n, board, row, col)) {
            board[row][col] = 1;
            count += countSolveNQueen(n, board, row + 1);

            // need to backtrack - i.e. try next column
            board[row][col] = 0;
        }
    }
    return count;
}

int nQueen(int n) {
    int board[20][20] {};
    return countSolveNQueen(n, board);
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (nQueen(4) == 2) << '\n';
    std::cout << (nQueen(1) == 1) << '\n';
}
