#include <cmath>
#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter an integer < 500: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "NO\n";
        return 0;
    }

    bool is_prime { true };
    for (int i { 2 }; i < std::sqrt(n); ++i) {
        if (n % i == 0) {
            is_prime = false;
        }
    }
    std::cout << (is_prime ? "YES\n" : "NO\n");
}