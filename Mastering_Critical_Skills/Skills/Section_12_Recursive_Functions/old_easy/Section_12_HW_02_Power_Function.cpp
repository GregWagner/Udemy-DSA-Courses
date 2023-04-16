#include <iostream>

auto my_pow(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * my_pow(base, exponent - 1);
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::cout << (my_pow(7, 3) == 343) << '\n';
}