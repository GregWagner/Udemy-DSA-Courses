#include <iostream>

auto isPrime(int n) -> bool {
    for (int i { 2 }; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    int a[101][101];

    std::cout << "Enter the number of rows and colums: ";
    int rows {}, columns {};
    std::cin >> rows >> columns;

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    std::cout << "Enter the number of queries: ";
    int q {};
    std::cin >> q;

    while (q--) {
        std::cout << "Enter i, j, r, and c: ";
        int i {}, j {}, r {}, c {};
        std::cin >> i >> j >> r >> c;

        int count {};
        for (int row { i }; row < i + r; ++row) {
            for (int col { j }; col < j + c; ++col) {
                if (isPrime(a[row][col])) {
                    ++count;
                }
            }
        }
        std::cout << count << '\n';
    }
}