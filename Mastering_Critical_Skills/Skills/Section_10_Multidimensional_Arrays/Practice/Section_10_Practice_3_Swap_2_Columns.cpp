#include <iostream>

auto main() -> int {
    int a[101][101];
    int rows {}, cols {};
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < cols; ++c) {
            std::cin >> a[r][c];
        }
    }

    int col1 {}, col2 {};
    std::cout << "Enter the 2 columns to swap: ";
    std::cin >> col1 >> col2;

    for (int r {}; r < rows; ++r) {
        std::swap(a[r][col1], a[r][col2]);
    }

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < cols; ++c) {
            std::cout << a[r][c] << ' ';
        }
        std::cout << '\n';
    }
}
