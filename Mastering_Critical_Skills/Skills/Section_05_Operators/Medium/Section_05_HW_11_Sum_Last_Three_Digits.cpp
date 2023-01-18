#include <iostream>

auto main() -> int {
    int num {};
    std::cout << "Enter a number: ";
    std::cin >> num;

    int sum { (num % 10) + (num / 10 % 10) + (num / 100 % 10) };
    std::cout << sum << '\n';
}