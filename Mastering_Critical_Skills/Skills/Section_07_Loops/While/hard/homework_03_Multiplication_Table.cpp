#include <iostream>

auto main() -> int {
    std::cout << "Enter n and m: ";
    int n {}, m {};
    std::cin >> n >> m;

    int x { 1 };
    int y { 1 };
    while (x <= n) {
        y = 1;
        while (y <= m) {
            std::cout << x << " * " << y << " = " << x * y << '\n';
            ++y;
        }
        ++x;
    }
}