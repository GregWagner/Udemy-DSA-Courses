/*
 * Reverse all the elemennts in an array
 *
 */
#include <iostream>

void print_array(int *a, size_t n) {
    for (size_t i {0}; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    int numberOfElements {};
    std::cout << "Enter the number of elements: ";
    std::cin >> numberOfElements;
    int *arr = new int[numberOfElements];

    std::cout << "Enter each arr element:\n";
    for (int i {}; i < numberOfElements; ++i) {
        std::cin >> arr[i]; 
    }

    int startingIndex {0};
    int endingIndex {numberOfElements - 1};

    while (startingIndex < endingIndex) {
        std::swap(arr[startingIndex], arr[endingIndex]);
        ++startingIndex;
        --endingIndex;
    }
    print_array(arr, numberOfElements);
}

