#include <iostream>

auto is_prime(int num) {
    for (int i { 2 }; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

auto nth_prime(int n) {
    int current_number { 1 };
    int prime_count {};
    while (prime_count != n) {
        ++current_number;
        if (is_prime(current_number)) {
            ++prime_count;
        }
    }
    return current_number;
}

auto main() -> int {
    std::cout << "Nth Prime of 6 is " << nth_prime(6) << '\n';
}