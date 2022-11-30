/*
 * Spiral Print
 * Write a function that takes in an nxm 2D array and prints
 * all array element in spiral order. Start from top let corner
 * and goes to the right, then procees in a spiral pattern until
 * every elemment is visisted.
 *
 * 1  2  3  4
 * 5  6  7  8
 * 9  10 11 12
 * 13 14 15 16
 *
 * 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 *
 * ToDo: Check if odd number of rows/columns works
 */
#include <iostream>

void print(int a[][4], int rows, int cols) {
    int starting_row {};
    int ending_row { rows - 1 };
    int starting_col {};
    int ending_col { cols - 1 };

    while ((starting_col <= ending_col) && (starting_row <= ending_row)) {
        // print top row
        for (int col { starting_col }; col <= ending_col; ++col) {
            std::cout << a[starting_row][col] << ' ';
        }

        // print right column
        for (int row { starting_row + 1 }; row <= ending_row; ++row) {
            std::cout << a[row][ending_col] << ' ';
        }

        // print bottom row
        for (int col { ending_col - 1 }; col >= starting_col; --col) {
            // avoid  duplicate printing of elements
            if (starting_row != ending_row) {
                std::cout << a[ending_row][col] << ' ';
            }
        }

        // print left colum
        for (int row { ending_row - 1 }; row >= starting_row + 1; --row) {
            // avoid  duplicate printing of elements
            if (starting_col != ending_col) {
                std::cout << a[row][starting_col] << ' ';
            }
        }

        ++starting_row;
        --ending_row;
        ++starting_col;
        --ending_col;
    }
    std::cout << '\n';
}

int main() {
    int a[][4] = {
        {1,   2,  3,  4},
        { 12, 13, 14, 5},
        { 11, 16, 15, 6},
        { 10, 9,  8,  7}
    };

    print(a, 4, 4);
}
