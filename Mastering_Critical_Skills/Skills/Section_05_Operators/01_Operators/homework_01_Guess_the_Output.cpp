#include <iostream>

auto main() -> int {
    int a {};
    int b { 1 };

    std::cout << a++ << "\n";   // 0    a=1 b=1
    std::cout << ++a << "\n";   // 2    a=2 b=1
    a += 2 * b + 1;             // a=5 b=1
    b = ++a * 2;                // a=6 b=12
    std::cout << a << " " << b << "\n"; // 6 12

    b = a;                      // a=b=6
    a = 12 + a / 3 / 2 - 2 * 2; // a=9 b=6
    std::cout << a << "\n";     // 9

    a = b;                      // a=b=6
    a = ((12 + a) / 3 / 2 - 2) * 2;
    std::cout << a << "\n";     // 2
}
