#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;

    std::cout << "Enter operation (-1 or 1): ";
    int b {};
    std::cin >> b;

    // convert operation to 0 or 1
    // if b is -1 opIsZero = 0
    //         opIsNotZero = 1
    // if b is  1 opIsZero = 1
    //         opIsNotZero = 0
    int opIsOne = (b + 1) / 2;
    // he used 1 - opIsOne
    int opIsNotOne = (b - 2) / -2;
    std::cout << opIsOne << ' ' << opIsNotOne << '\n';

    std::cout << opIsNotOne * (2 * a + 1) + opIsOne * (a * a) << '\n';
}