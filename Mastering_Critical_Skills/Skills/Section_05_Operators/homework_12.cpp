#include <iostream>

auto main() -> int {
    int num {};
    std::cout << "Enter a number: ";
    std::cin >> num;

    int result { num / 1000 % 10 };
    std::cout << result << '\n';
}