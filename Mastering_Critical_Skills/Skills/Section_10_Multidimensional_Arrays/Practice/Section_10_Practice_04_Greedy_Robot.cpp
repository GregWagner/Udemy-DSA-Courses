#include <iostream>

auto main() -> int {
    int a[100][100];
    int rows {}, cols {};
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;

    for (int i {}; i < rows; ++i) {
        for (int j {}; j < cols; ++j) {
            std::cin >> a[i][j];
        }
    }

    int i {}, j {}, sum {};
    const int DI[] { 1, 0, 1 };
    const int DJ[] { 0, 1, 1 };

    while (i < rows && j < cols) {
        sum += a[i][j];

        int next_value {}, best_i { -1 }, best_j { -1 };
        for (int d {}; d < 3; ++d) {
            int next_i = next_i + DI[d];
            int next_j = next_j + DJ[d];

            if (next_i < rows && next_j < cols) {
                if (best_i == -1 || next_value < a[next_i][next_j]) {
                    next_value = a[next_i][next_j];
                    best_i = next_i;
                    best_j = next_j;
                }
            }

            if (best_i == -1) {
                break;
            }
            i = best_i;
            j = best_j;
        }
    }
    std::cout << "Total: " << sum << '\n';
}