#include <iostream>

auto main() -> int {
    double b {};
    double a {};
    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;

    double d { a / b };
    std::cout << d - static_cast<int>(d) << '\n';
}