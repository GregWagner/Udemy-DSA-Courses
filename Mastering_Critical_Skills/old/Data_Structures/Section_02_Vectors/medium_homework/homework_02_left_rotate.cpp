#include <iostream>
#include <vector>

auto leftRotation(std::vector<int>& arr) {
    int first {arr[0]};
    for (size_t i {0}; i < arr.size() - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = first;
}

auto main() -> int {
    std::vector<int> arr {1, 2, 3, 4, 5};
    leftRotation(arr);
    for (auto ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << '\n';
}
