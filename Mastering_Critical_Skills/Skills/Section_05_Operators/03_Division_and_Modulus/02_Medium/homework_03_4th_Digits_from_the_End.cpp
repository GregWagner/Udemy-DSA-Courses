#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;

    std::cout << num / 1000 % 10 << '\n';
}