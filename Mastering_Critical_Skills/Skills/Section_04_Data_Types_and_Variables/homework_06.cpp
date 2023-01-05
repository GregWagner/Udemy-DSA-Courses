/*
 * Swap 3 numbers
 */
#include <iostream>

int main() {
    int num1 {}, num2 {}, num3 {};
    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    int temp { num1 };
    num1 = num2;
    num2 = num3;
    num3 = temp;

    std::cout << num1 << ' ' << num2 << ' ' << num3 << '\n';
}