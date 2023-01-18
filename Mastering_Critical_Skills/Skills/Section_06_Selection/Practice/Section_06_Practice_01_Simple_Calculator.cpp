#include <iostream>

auto main() -> int {
    int a {};
    char op {};
    int b {};
    std::cout << "Enter calculator expression: ";
    std::cin >> a >> op >> b;

    if (op == '+') {
        std::cout << a << " + " << b << " = " << a + b << '\n';
    } else if (op == '-') {
        std::cout << a << " - " << b << " = " << a - b << '\n';
    } else if (op == '*') {
        std::cout << a << " * " << b << " = " << a * b << '\n';
    } else if (op == '/') {
        std::cout << a << " / " << b << " = " << a / b << '\n';
    } else {
        std::cout << "Unknown opertions\n";
    }
}