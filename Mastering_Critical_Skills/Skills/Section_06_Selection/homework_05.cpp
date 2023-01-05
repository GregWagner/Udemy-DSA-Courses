#include <iostream>

int main() {
    int input {};

    std::cout << "Enter 10 integers: ";
    std::cin >> input;
    int largest { input };

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cin >> input;
    largest = std::max(largest, input);

    std::cout << largest << '\n';
}