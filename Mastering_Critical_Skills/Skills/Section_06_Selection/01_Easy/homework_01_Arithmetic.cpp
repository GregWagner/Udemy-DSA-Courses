#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 integers: ";
    int a {}, b {};
    std::cin >> a >> b;

    bool aIsEven = a % 2 == 0;
    bool bIsEven = b % 2 == 0;

    if (!aIsEven && !bIsEven) {
        std::cout << a * b << '\n';
    } else if (aIsEven && bIsEven) {
        std::cout << a / b << '\n';
    } else if (!aIsEven) {
        std::cout << a + b << '\n';
    } else {
        std::cout << a - b << '\n';
    }
}