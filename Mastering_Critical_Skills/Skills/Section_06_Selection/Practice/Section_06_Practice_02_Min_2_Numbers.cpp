#include <iostream>

auto main() -> int {
    int a {};
    int b {};
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    if (a < b) {
        std::cout << a << '\n';
    } else if (b < a) {
        std::cout << b << '\n';
    } else {
        std::cout << a << " equals " << b << '\n';
    }
}