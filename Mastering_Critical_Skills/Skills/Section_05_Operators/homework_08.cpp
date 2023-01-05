#include <iostream>

int main() {
    double a {}, b {};
    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;

    double d { a / b };
    std::cout << d - static_cast<int>(d) << '\n';
}