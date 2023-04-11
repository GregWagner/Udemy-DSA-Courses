#include <iostream>

auto main() -> int {
    std::cout << "Enter n, m, and sum: ";
    int n {}, m {}, sum {};
    std::cin >> n >> m >> sum;

    for (int i { 1 }; i <= n; ++i) {
        int j { sum - i };
        if (j > 0 && j <= m) {
            std::cout << i << " + " << j << " = " << i + j << '\n';
        }
    }
}