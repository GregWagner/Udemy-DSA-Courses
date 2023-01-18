#include <iostream>

auto main() -> int {
    int a {};
    int b {};
    std::cout << "Enter 2 integers: ";
    std::cin >> a >> b;

    bool a_is_even = a % 2 == 0;
    bool b_is_even = b % 2 == 0;

    if (!a_is_even && !b_is_even) {
        std::cout << a * b << '\n';
    } else if (a_is_even && b_is_even) {
        std::cout << a / b << '\n';
    } else if (!a_is_even && b_is_even) {
        std::cout << a + b << '\n';
    } else {
        std::cout << a - b << '\n';
    }
}