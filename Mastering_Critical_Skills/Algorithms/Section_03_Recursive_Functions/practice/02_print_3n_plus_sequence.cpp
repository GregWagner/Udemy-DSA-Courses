#include <iostream>

auto print_sequence(int n) -> void {
    std::cout << n << ' ';
    if (n == 1) {
        std::cout << '\n';
        return;
    }
    if (n % 2 == 0) {
        print_sequence(n / 2);
    } else {
        print_sequence(3 * n + 1);
    }
}

auto main() -> int {
    std::cout << "Enter n: ";
    int number {};
    std::cin >> number;

    print_sequence(number);
}
