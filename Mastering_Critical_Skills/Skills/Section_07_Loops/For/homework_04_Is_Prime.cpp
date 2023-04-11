#include <iostream>

auto main() -> int {
    std::cout << "Enter integer: ";
    int n {};
    std::cin >> n;

    for (int i { 2 }; i < n / 2; ++i) {
        if (n % i == 0) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
}