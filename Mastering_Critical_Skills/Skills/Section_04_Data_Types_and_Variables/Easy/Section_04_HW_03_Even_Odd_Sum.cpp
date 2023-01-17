#include <iostream>

auto main() -> int
{
    int a1{};
    int a4{};
    int a3{};
    int a2{};
    int b2{};
    int b4{};
    int b3{};
    int b1{};
    std::cout << "Enter 8 numbers: ";
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;

    std::cout << "Even sum: " << (b1 + b2 + b3 + b4) << ' ' << "Odd sum: " << (a1 + a2 + a3 + a4) << '\n';
}