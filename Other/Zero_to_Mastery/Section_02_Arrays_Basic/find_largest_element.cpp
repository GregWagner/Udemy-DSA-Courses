/*
 * Finding the largest element in an array
 */
#include <iostream>

int main() {
    int numberOfElements {};
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;
    int* arr = new int[numberOfElements];

    std::cout << "Enter each arr element:\n";
    for (int i {}; i < numberOfElements; ++i) {
        std::cin >> arr[i];
    }

    int largest { arr[0] };
    for (int i { 1 }; i < numberOfElements; ++i) {
        largest = arr[i] > largest ? arr[i] : largest;
    }
    std::cout << "Largest element was " << largest << ".\n";
}
