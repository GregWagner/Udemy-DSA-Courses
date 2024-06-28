#include <iostream>

auto length_3n_plus_1(int n) -> int {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return 1 + length_3n_plus_1(n / 2);
    }
    return 1 + length_3n_plus_1(3 * n + 1);
}

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::cout << length_3n_plus_1(n) << '\n';
}
