/*
 * Print an array in reverse order
 */
#include <iostream>

int main() {
    int numberOfElements {};
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;
    int *arr = new int[numberOfElements];

    std::cout << "Enter each arr element:\n";
    for (int i {}; i < numberOfElements; ++i) {
        std::cin >> arr[i]; 
    }

    for (int i {numberOfElements - 1}; i >= 0; --i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}
