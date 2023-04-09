/*
 * Power
 */
#include <iostream>

int power(int base, int exponent = 1) {
    if (exponent == 1) {
        return base;
    }
    return base * power(base, exponent - 1);
}

int main() {
    std::cout << power(2, 3) << '\n';
}
