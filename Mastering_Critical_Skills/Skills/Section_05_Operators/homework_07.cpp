#include <iostream>

int main() {
    int a1 {}, a2 {}, a3 {};
    int b1 {}, b2 {};
    std::cout << "Enter 5 numbers: ";
    std::cin >> a1 >> a2 >> a3 >> b1 >> b2;

    double first_sum = a1 + a2 + a3;
    double second_sum = b1 + b2;
    std::cout << "Average: " << (first_sum + second_sum) / 5.0 << '\n';
    std::cout << first_sum / second_sum << '\n';
    std::cout << (first_sum / 3.0) / (second_sum / 2.0) << '\n';
}