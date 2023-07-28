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

    int sumLeftDiagonal {};
    for (size_t index {}; index < rows && index < columns; ++index) {
        sumLeftDiagonal += a[index][index];
    }

    int sumRightDiagonal {};
    for (size_t r {}, c { columns - 1 }; r < rows && c >= 0; ++r, --c) {
        sumRightDiagonal += a[r][c];
    }

    int sumLastRow {};
    size_t r = rows - 1;
    for (size_t c {}; c < columns; ++c) {
        sumLastRow += a[r][c];
    }

    int sumLastCol {};
    size_t c = columns - 1;
    for (size_t r {}; r < rows; ++r) {
        sumLastCol += a[r][c];
    }

    std::cout << sumLeftDiagonal << ' ' << sumRightDiagonal << '\n';
    std::cout << sumLastRow << ' ' << sumLastCol << '\n';
}