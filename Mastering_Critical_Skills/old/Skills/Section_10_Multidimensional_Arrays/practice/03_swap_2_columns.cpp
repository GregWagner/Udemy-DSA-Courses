#include <algorithm>
#include <iostream>

auto main() -> int {
    int a[100][100];
    std::cout << "Enter the number of rows and columns: ";
    size_t rows {};
    size_t columns {};
    std::cin >> rows >> columns;

    for (size_t r {}; r < rows; ++r) {
        for (size_t c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    std::cout << "Enter the 2 columns to swap: ";
    int first {};
    int second {};
    std::cin >> first >> second;

    for (size_t r {}; r < rows; ++r) {
        std::swap(a[r][first], a[r][second]);
    }

    for (size_t r {}; r < rows; ++r) {
        for (size_t c {}; c < columns; ++c) {
            std::cout << a[r][c] << ' ';
        }
        std::cout << '\n';
    }
}
