#include <iostream>

auto my_pow(int value, int p = 2) -> int {
    if (p == 0) {
        return 1;
    }
    return value * my_pow(value, p - 1);
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::cout << (my_pow(7, 3) == 343) << '\n';
    std::cout << (my_pow(7) == 49) << '\n';
    std::cout << (my_pow(7, 0) == 1) << '\n';
}