#include <iostream>

auto main() -> int {
    int a[101][101];

    const int NUMBER_OF_DIRECTIONS { 8 };
    int x[] { -1, -1, -1, 0, 0, 1, 1, 1 };
    int y[] { -1, 0, 1, -1, 1, -1, 0, 1 };

    std::cout << "Enter the number of rows and columns: ";
    int rows {}, columns {};
    std::cin >> rows >> columns;

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            std::cin >> a[r][c];
        }
    }

    for (int r {}; r < rows; ++r) {
        for (int c {}; c < columns; ++c) {
            bool isMountain { true };
            for (int i {}; i < NUMBER_OF_DIRECTIONS; ++i) {
                int nextRow { r + x[i] };
                int nextCol { c + y[i] };
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < columns) {
                    if (a[r][c] <= a[nextRow][nextCol]) {
                        isMountain = false;
                        break;
                    }
                }
            }
            if (isMountain) {
                std::cout << r << ' ' << c << '\n';
            }
        }
    }
}