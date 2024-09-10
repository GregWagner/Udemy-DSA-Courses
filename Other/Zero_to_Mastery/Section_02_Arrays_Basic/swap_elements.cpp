/*
 * Swap 2 numbers
 */
#include <iostream>

void print(const std::string &prompt, unsigned a, unsigned b) {
    std::cout << prompt << '\n'
        << "a = " << a << '\n'
        << "b = " << b << '\n';
}

void swap_1(int a, int b) {
    print("Before swap: ", a, b);

    int temp {a};
    a = b;
    b = temp;

    print("After swap: ", a, b);
}

void swap_2(unsigned a, unsigned b) {
    print("Before swap: ", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    print("After swap: ", a, b);
}

void swap_3(int a, int b) {
    print("Before swap: ", a, b);

    std::swap(a, b);

    print("After swap: ", a, b);
}

int main() {
    int a {};
    int b {};
    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;

    swap_1(a, b);
    swap_2(a, b);
    swap_3(a, b);
}
