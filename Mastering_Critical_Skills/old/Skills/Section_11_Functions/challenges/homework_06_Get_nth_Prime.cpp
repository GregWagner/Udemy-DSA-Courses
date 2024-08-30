#include <cmath>
#include <iostream>

auto is_prime(int num) -> bool {
    for (int i { 2 }; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

auto nth_prime(int n) -> int {
    int currentNumber { 2 };
    while (true) {
        if (is_prime(currentNumber)) {
            --n;
            if (n == 0) {
                return currentNumber;
            }
        }
        ++currentNumber;
    }
}

auto main() -> int {
    std::cout << "Enter number: ";
    int n {};
    std::cin >> n;
    std::cout << nth_prime(n) << '\n';
}