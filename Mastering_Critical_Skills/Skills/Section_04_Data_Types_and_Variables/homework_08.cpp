/*
 * Sum numbers from 1 to n
 */
#include <iostream>

int main() {
    int n {};
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << (n * (n + 1)) / 2 << '\n';
}