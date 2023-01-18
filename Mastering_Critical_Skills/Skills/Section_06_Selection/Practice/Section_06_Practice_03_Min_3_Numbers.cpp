#include <iostream>

auto main() -> int {
    int a {}, b {}, c {};
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;

    if (a < b && a < c) {
        std::cout << a << '\n';
    } else if (b < a && b < c) {
        std::cout << b << '\n';
    } else if (c < a && c < b) {
        std::cout << c << '\n';
    } else {
        std::cout << "There is no one minimum\n";
    }
}