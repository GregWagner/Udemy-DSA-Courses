/*
 * Calculate the sum of the elements of an array
 */
#include <iostream>

int main() {
    int numberOfElements {};
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;
    int* arr = new int[numberOfElements];

    std::cout << "Enter each arr element:\n";
    for (size_t i {}; i < numberOfElements; ++i) {
        std::cin >> arr[i];
    }

    int sum {};
    for (size_t i {}; i < numberOfElements; ++i) {
        sum += arr[i];
    }

    std::cout << "The sum of the array is " << sum << ".\n";
}
