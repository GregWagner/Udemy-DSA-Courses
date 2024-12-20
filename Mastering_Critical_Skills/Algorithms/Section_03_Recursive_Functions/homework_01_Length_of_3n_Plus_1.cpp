#include <iostream>

auto length_of_3n_plus_1(int n) -> int {
    if (n <= 1) {
        return n;
    }
    if (n % 2 == 0) {
        return 1 + length_of_3n_plus_1(n / 2);
    }
    return 1 + length_of_3n_plus_1(3 * n + 1);
}

auto main() -> int {
    std::cout << "Enter n: ";
    int num {};
    std::cin >> num;
    std::cout << length_of_3n_plus_1(num) << '\n';
}
