#include <iostream>

auto main() -> int {
    int a[100][100];
    int rows {}, cols {};
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < cols; ++c) {
            std::cin >> a[r][c];
        }
    }

    int sum_of_left_diag {};
    int max_index = std::min(rows, cols);
    for (int i {}; i < max_index; ++i) {
        sum_of_left_diag += a[i][i];
    }

    int sum_of_right_diag {};
    int row {};
    for (int i { cols - 1 }; i >= 0; --i) {
        sum_of_right_diag += a[row][i];
        ++row;
    }

    int sum_last_row {};
    row = rows - 1;
    for (int i {}; i < cols; ++i) {
        sum_last_row += a[row][i];
    }

    int sum_last_col {};
    int col = cols - 1;
    for (int i {}; i < rows; ++i) {
        sum_last_col += a[i][col];
    }

    std::cout << sum_of_left_diag << ' ' << sum_of_right_diag << '\n';
    std::cout << sum_last_row << ' ' << sum_last_col << '\n';
}
