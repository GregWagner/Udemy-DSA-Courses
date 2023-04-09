/*
 * Sum of Digits
 */
#include <iostream>

int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    std::cout << sumOfDigits(5) << '\n';
    std::cout << sumOfDigits(12345) << '\n';
}
