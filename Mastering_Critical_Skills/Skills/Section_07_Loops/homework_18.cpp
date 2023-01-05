#include <iostream>

int main() {
    int n {};
    std::cout << "Enter largest number to check: ";
    std::cin >> n;

    bool is_first { true };
    std::cout << "2, ";
    for (int i { 3 }; i <= n; i += 2) {
        bool is_prime { true };
        for (int j { i + 1 }; j < n; ++j) {
            if (i % j == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {
            if (is_first) {
                std::cout << i;
                is_first = false;
            } else {
                std::cout << ", " << i;
            }
        }
    }
    std::cout << '\n';
}