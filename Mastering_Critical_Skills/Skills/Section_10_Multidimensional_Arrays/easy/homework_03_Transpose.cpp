#include <iostream>

auto main() -> int {
    int a[101][101];

    std::cout << "Enter number of rows and columns: ";
    int rows {}, columns {};
    std::cin >> rows >> columns;

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    int t[101][101];
    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            t[c][r] = a[r][c];
        }
    }

    for (int r {}; r < columns; ++r) {
        for (int c {}; c < rows; ++c) {
            std::cout << t[r][c] << ' ';
        }
        std::cout << '\n';
    }
}