#include <iostream>

auto main() -> int {
    double a{}, b{};
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
}
