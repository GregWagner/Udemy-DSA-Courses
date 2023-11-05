/*
 * Print Number
 */
#include <iostream>

void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);
    std::cout << n << ' ';
}

int main() {
    printNumbers(5);
    std::cout << '\n';
}
