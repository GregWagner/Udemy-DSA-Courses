#include <iostream>

auto main() -> int {
    std::cout << "Enter 3 numbers: ";
    int num1 {}, num2 {}, num3 {};
    std::cin >> num1 >> num2 >> num3;

    int smallest = num1;
    if (num2 < smallest) {
        smallest = num2;
    }
    if (num3 < smallest) {
        smallest = num3;
    }

    int largest = num1;
    if (num2 > largest) {
        largest = num2;
    }
    if (num3 > largest) {
        largest = num3;
    }

    int middle = (num1 + num2 + num3) - smallest - largest;

    std::cout << smallest << ' ' << middle << ' ' << largest << '\n';
}