/*
 * Print an array in reverse order
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

    for (size_t i {numberOfElements}; i > 0; --i) {
        std::cout << arr[i - 1] << ' ';
    }
    std::cout << '\n';
}
