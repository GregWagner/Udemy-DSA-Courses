#include <iostream>

int main() {
    int a[101][101];
    int n {}, m {};
    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    for (int r {}; r < n; ++r) {
        for (int c {}; c < m; ++c) {
            std::cin >> a[r][c];
        }
    }

    for (int r {}; r < n; ++r) {
        for (int c {}; c < m; ++c) {
            int starting_row = r > 0 ? r - 1 : r;
            int starting_col = c > 0 ? c - 1 : c;
            int ending_row = r < n - 1 ? r + 1 : r;
            int ending_col = c < m - 1 ? c + 1 : c;
            int current_value { a[r][c] };
            bool isMountain { true };
            for (int row { starting_row }; row <= ending_row; ++row) {
                for (int col { starting_col }; col <= ending_col; ++col) {
                    if (current_value < a[row][col]) {
                        isMountain = false;
                    }
                }
            }
            if (isMountain) {
                std::cout << r << ' ' << c << '\n';
            }
        }
    }
}