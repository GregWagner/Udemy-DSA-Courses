/*
 * Calculate the sum of the elements of an array
 */
#include <iostream>
#include <vector>

int main() {
    size_t numberOfElements {};
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;
    std::vector<int> arr(numberOfElements, 0);

    std::cout << "Enter each arr element:\n";
    for (size_t i {}; i < numberOfElements; ++i) {
        std::cin >> arr[i];
    }

    int sum {};
    for (auto element : arr) {
        sum += element;
    }

    std::cout << "The sum of the array is " << sum << ".\n";
}
