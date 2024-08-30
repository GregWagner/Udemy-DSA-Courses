#include <iostream>
#include <vector>

auto pop(std::vector<int>& arr, int index) -> int {
    int val {arr[index]};
    for (size_t i {index}; i < arr.size() - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = 0;
    return val;
}

auto main() -> int {
    std::vector<int> arr {1, 2, 3, 4, 5};
    std::cout << pop(arr, 3) << '\n';
    for (auto ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << '\n';
}
