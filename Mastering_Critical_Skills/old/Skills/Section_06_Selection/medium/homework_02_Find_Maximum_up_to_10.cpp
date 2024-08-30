#include <iostream>

auto main() -> int {
    std::cout << "Enter the nuumber of integers: ";
    int n {};
    std::cin >> n;

    int largest {};
    int num {};

    if (n > 0) {
        std::cin >> num;
        largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }
    if (n > 0) {
        std::cin >> num;
        if (num > largest) largest = num;
        --n;
    }

    std::cout << largest << '\n';
}