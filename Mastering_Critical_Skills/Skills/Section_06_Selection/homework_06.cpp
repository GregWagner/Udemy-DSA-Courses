#include <iostream>

int main() {
    int input {};

    int n {};
    std::cout << "Enter the number of inputs: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    std::cin >> input;
    --n;
    int largest { input };

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    if (--n >= 0) {
        std::cin >> input;
        largest = std::max(largest, input);
    }

    std::cout << largest << '\n';
}