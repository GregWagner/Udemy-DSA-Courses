#include <iostream>

auto main() -> int {
    std::cout << "Enter n, m, and w: ";
    int n {}, m {}, w {};
    std::cin >> n >> m >> w;

    for (int a { 1 }; a <= n; ++a) {
        for (int b { 1 }; b <= n; ++b) {
            int c { a + b };
            if (c > 0 && c <= w) {
                std::cout << a << " + " << b << " = " << c << '\n';
            }
        }
    }
}