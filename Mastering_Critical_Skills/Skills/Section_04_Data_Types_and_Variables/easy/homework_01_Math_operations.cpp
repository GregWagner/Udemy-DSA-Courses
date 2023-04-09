#include <iostream>

auto main() -> int {
    std::cout << "Enter two numbers: ";
    double num1 {};
    double num2 {};
    std::cin >> num1 >> num2;

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n';
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
}
