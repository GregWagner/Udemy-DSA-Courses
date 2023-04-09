/*
 * Multiplication
 */
#include <iostream>

int multiplication(int a, int b) {
    if (b == 1) {
        return a;
    }
    return a + multiplication(a, b - 1);
}

int main() {
    std::cout << multiplication(10, 4) << '\n';
    std::cout << multiplication(2, 7) << '\n';
}
