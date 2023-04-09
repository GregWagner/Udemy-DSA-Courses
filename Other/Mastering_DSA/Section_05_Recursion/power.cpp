/*
 * Calculates the nth power of m
 * m^n = m * m * m * m ... ( n-1 times ) * m
 */
#include <iostream>

int pow(int m, int n) {
    if (n == 0) {
        return 1;
    }
    return pow(m, n - 1) * m;
}

int fastPower(int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return fastPower(m * m, n / 2);
    }
    return m * fastPower(m * m, (n - 1) / 2);
}

int main() {
    std::cout << pow(2, 3) << '\n';
    std::cout << fastPower(2, 3) << '\n';
    std::cout << pow(1, 3) << '\n';
    std::cout << fastPower(1, 3) << '\n';
}
