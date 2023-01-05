#include <iostream>

int main() {
    int a {}, b {};
    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;

    double d = a / b;
    std::cout << a - (b * d) << '\n';
}