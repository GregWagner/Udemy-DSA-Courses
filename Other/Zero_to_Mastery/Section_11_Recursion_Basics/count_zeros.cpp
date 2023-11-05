/*
 * Count Zeros
 */
#include <iostream>

int countZeros(int n) {
    if (n < 10) {
        return (n == 0 ? 1 : 0);
    }
    return (n % 10 == 0) ? 1 + countZeros(n / 10) : countZeros(n / 10);
}

int main() {
    std::cout << countZeros(102030) << '\n';
    std::cout << countZeros(123) << '\n';
}
