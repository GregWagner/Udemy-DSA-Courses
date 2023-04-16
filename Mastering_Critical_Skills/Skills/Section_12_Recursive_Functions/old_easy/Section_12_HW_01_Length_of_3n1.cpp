#include <iostream>

auto count_seq(int n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        n /= 2;
    } else {
        n = 3 * n + 1;
    }

    return 1 + count_seq(n);
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::cout << (count_seq(6) == 9) << '\n';
}