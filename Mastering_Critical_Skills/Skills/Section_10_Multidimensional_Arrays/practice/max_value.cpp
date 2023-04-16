#include <iostream>

auto main() -> int {
    int a[101][101];

    std::cout << "Enter rows and columns: ";
    int rows {}, columns {};
    std::cin >> rows >> columns;

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    int maxRow {};
    int maxCol {};
    int maxValue { a[maxRow][maxCol] };
    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            if (a[r][c] >= maxValue) {
                maxRow = r;
                maxCol = c;
                maxValue = a[maxRow][maxCol];
            }
        }
    }
    std::cout << "Max value at position " << maxRow << ' ' << maxCol
              << " with value = " << maxValue << '\n';
}