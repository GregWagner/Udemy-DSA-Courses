/*
 * Math operations
 */
#include <iostream>

auto main() -> int {
    int a {};
    int b {};
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << '\n';
    std::cout << a << " - " << b << " = " << a - b << '\n';
    std::cout << a << " / " << b << " = " << a / b << '\n';
    std::cout << a << " * " << b << " = " << a * b << '\n';
}