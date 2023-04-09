#include <iostream>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::cout << (n * (n + 1)) / 2 << '\n';
}