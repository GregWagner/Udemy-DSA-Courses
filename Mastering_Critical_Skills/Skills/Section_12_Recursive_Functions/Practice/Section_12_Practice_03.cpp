#include <iostream>

auto print_seq(int n) {
    if (n == 1) {
        std::cout << '\n';
        return;
    }
    std::cout << n << ' ';
    if (n % 2 == 0) {
        n /= 2;
    } else {
        n = 3 * n + 1;
    }

    print_seq(n);
}

auto main() -> int {
    print_seq(6);
}