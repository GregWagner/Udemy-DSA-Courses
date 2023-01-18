#include <iostream>

auto main() -> int {
    int a {};
    int b {};
    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;

    double d = a / b;
    std::cout << a - (b * d) << '\n';
}