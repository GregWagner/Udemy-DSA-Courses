#include <iostream>

auto main() -> int {
    std::cout << "Enter two numbers: ";
    int a, b;
    std::cin >> a >> b;

    double answer = static_cast<double>(a) / b;
    double fraction = answer - (a / b);

    std::cout << fraction << '\n';
}