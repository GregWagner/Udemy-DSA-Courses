/*
 * Finding the largest element in an array
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

    int largest { arr[0] };
    for (const auto element: arr) {
        largest = std::max(element, largest);
    }
    std::cout << "Largest element was " << largest << ".\n";
}
