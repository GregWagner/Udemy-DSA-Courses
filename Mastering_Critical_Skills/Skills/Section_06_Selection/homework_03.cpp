#include <iostream>

auto main() -> int {
    int a {};
    int b{};
    int c{};
    std::cout << "Enter three integers: ";
    std::cin >> a >> b >> c;

    int max { -1 };
    if (a < 100 && a > max) {
        max = a;
    }
    if (b < 100 && b > max) {
        max = b;
    }
    if (c < 100 && c > max) {
        max = c;
    }
    std::cout << max << '\n';
}