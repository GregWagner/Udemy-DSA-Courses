#include <iostream>

auto main() -> int {
    std::cout << "Enter a number: ";
    int n{};
    std::cin >> n;

    std::cout << (n * (n + 1)) / 2 << '\n';
}
