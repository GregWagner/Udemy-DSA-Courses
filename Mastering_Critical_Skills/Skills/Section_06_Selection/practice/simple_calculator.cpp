#include <iostream>

auto main() -> int {
    std::cout << "Enter number op number: ";
    int num1 {}, num2 {};
    char op {};
    std::cin >> num1 >> op >> num2;

    if (op == '+') {
        std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
    } else if (op == '-') {
        std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
    } else if (op == '*') {
        std::cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
    } else if (op == '/') {
        std::cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n';
    } else {
        std::cout << "Invalid operations.\n";
    }
}