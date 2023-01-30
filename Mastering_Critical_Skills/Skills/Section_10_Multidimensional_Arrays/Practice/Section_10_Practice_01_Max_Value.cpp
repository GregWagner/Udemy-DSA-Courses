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

    int max_row {};
    int max_column {};
    int max_value { a[0][0] };
    for (int r {}; r < rows; ++r) {
        for (int c {}; c < cols; ++c) {
            if (a[r][c] >= max_value) {
                max_value = a[r][c];
                max_row = r;
                max_column = c;
            }
        }
    }
    std::cout << "Max value at position " << max_row << ' '
              << max_column << " with value = " << max_value << '\n';
}