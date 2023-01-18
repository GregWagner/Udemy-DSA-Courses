#include <iostream>

auto main() -> int {
    int n {}, m {}, sum {};
    std::cout << "Enter n, m, and the sum: ";
    std::cin >> n >> m >> sum;

    for (int i { 1 }; i <= n; ++i) {
        for (int j { 1 }; j <= m; ++j) {
            if (i + j == sum) {
                std::cout << i << " + " << j << " = " << sum << '\n';
            }
        }
    }
}