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

    int queries {};
    std::cout << "Enter the number of queries: ";
    std::cin >> queries;

    while (queries--) {
        int row1 {}, row2 {};
        std::cout << "Enter the 2 rows to check: ";
        std::cin >> row1 >> row2;
        --row1;
        --row2;

        bool smaller { true };
        for (int col {}; col < cols; ++col) {
            if (a[row1][col] > a[row2][col]) {
                smaller = false;
            }
        }
        std::cout << (smaller ? "Yes\n" : "No\n");
    }
}