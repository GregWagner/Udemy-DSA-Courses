#include <iostream>

auto main() -> int {
    int n {}, m {}, w {};
    std::cout << "enter n, m, and w: ";
    std::cin >> n >> m >> w;

    for (int a { 1 }; a <= n; ++a) {
        for (int b { 1 }; b <= m; ++b) {
            int sum { a + b };
            if (sum >= 1 && sum <= w) {
                std::cout << a << " + " << b << " = " << sum << '\n';
            }
        }
    }
}