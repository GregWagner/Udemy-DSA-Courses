#include <iostream>

auto main() -> int {
    std::cout << "Enter 2 positive integers: ";
    int a, b;
    std::cin >> a >> b;

    int divide = a / b;
    int answer = a - (b * divide);

    std::cout << answer << '\n';
}