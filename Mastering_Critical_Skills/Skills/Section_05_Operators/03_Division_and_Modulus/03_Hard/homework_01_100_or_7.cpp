#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;

    bool isEven = num % 2 == 0;

    std::cout << isEven * 100 + !isEven * 7 << '\n';
}