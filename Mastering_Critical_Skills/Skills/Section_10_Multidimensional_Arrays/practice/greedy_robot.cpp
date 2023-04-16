#include <iostream>

auto main() -> int {
    int a[101][101];

    std::cout << "Enter the number of rows and columns: ";
    int rows {}, columns {};
    std::cin >> rows >> columns;

    for (size_t r {}; r < rows; ++r) {
        for (size_t c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    int xPosition {}, yPosition {};
    while (xPosition < columns && yPosition < rows) {
        // check right
    }
}