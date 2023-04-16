#include <iostream>

auto main() -> int {
    int a[101][101];

    std::cout << "Enter the number of rows and columns: ";
    size_t rows {}, columns {};
    std::cin >> rows >> columns;

    for (size_t r {}; r < rows; ++r) {
        for (size_t c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    std::cout << "Enter the number of queriers: ";
    int q {};
    std::cin >> q;

    while (q--) {
        std::cout << "Enter 2 rows to check: ";
        size_t first {}, second {};
        std::cin >> first >> second;

        --first;
        --second;
        bool smaller { true };
        for (size_t c {}; c < columns; ++c) {
            if (a[first][c] > a[second][c]) {
                smaller = false;
                break;
            }
        }
        std::cout << (smaller ? "YES" : "NO") << '\n';
    }
}