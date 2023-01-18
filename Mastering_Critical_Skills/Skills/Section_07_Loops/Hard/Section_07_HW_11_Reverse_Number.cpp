#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter a number: ";
    std::cin >> n;

    int new_n {};
    while (n) {
        new_n *= 10;
        new_n += n % 10;
        n /= 10;
    }
    std::cout << new_n << ' ' << new_n * 3 << '\n';
}