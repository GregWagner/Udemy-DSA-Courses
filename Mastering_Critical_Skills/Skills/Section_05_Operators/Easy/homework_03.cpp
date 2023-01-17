#include <iostream>

auto main() -> int {
    int a = 210;

    a /= 2;
    std::cout << a << "\n";         // 105

    std::cout << (a /= 3) << "\n";  // 35
    std::cout << (a /= 5) << "\n";  // 7
    std::cout << (a /= 7) << "\n";  // 1

    //               40 / 5 / 8
    std::cout << (2 + 3) * (5 - (-3)) / 5 / 8 << "\n";  // 1

    a = 10;
    std::cout << a++ + 10 << "\n";  // 20 a=11
    std::cout << ++a + 10 << "\n";  // 22 a=12
    std::cout << a-- + 10 << "\n";  // 22 a=11
    std::cout << --a + 10 << "\n";  // 20 a=10

    int b = 20;
    // Don't code this way
    std::cout << a++ + ++b << "\n"; // 31 a=11 b=21

    std::cout << a << "\n";         // 11
    ++a += 10; // Don't code this way
    std::cout << a << "\n";         // 22
}