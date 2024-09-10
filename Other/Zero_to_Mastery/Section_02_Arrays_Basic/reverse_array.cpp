/*
 * Reverse all the elemennts in an array
 *
 */
#include <iostream>
#include <vector>

void print_array( const std::vector<int> &a) {
    for (size_t i {0}; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    size_t numberOfElements {};
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;
    std::vector<int> arr(numberOfElements, 0);

    for (size_t i {}; i < numberOfElements; ++i) {
        std::cin >> arr[i];
    }

    size_t startingIndex {0};
    size_t endingIndex {numberOfElements - 1};

    while (startingIndex < endingIndex) {
        std::swap(arr[startingIndex], arr[endingIndex]);
        ++startingIndex;
        --endingIndex;
    }
    print_array(arr);
}

