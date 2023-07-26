#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;

    int sum { num % 10 + num / 10 % 10 + num / 100 % 10 };
    std::cout << sum << '\n';
}