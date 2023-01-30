#include <cmath>
#include <iostream>

void set_powers(int arr[], int len = 5, int m = 2) {
    for (int i {}; i < len; ++i) {
        arr[i] = std::pow(m, i);
    }
}

void print_array(int arr[], int len) {
    for (int i {}; i < len; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

auto main() -> int {
    int size {};
    std::cout << "Enter size of arrray: ";
    std::cin >> size;

    int power {};
    std::cout << "Enter power: ";
    std::cin >> power;

    int a[size];
    set_powers(a, size, power);
    print_array(a, size);
}