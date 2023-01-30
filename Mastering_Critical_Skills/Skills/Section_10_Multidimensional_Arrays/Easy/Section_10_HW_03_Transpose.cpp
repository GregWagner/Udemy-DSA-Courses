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

    int t[101][101];
    for (int r {}; r < rows; ++r) {
        for (int c {}; c < cols; ++c) {
            t[c][r] = a[r][c];
        }
    }

    std::cout << "----------------\n";
    for (int r {}; r < cols; ++r) {
        for (int c {}; c < rows; ++c) {
            std::cout << t[r][c] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}