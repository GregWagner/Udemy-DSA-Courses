/*
 * Count Digits
 */
#include <iostream>

int countDigits(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int main() {
    std::cout << countDigits(5) << '\n';
    std::cout << countDigits(12345) << '\n';
}
