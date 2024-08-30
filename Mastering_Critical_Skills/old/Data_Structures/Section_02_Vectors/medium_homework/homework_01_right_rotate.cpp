#include <iostream>
#include <vector>

auto rightRotation(std::vector<int>& arr) {
    int last {arr[arr.size() - 1]};
    for (size_t i {arr.size() - 1}; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

auto main() -> int {
    std::vector<int> arr {1, 2, 3, 4, 5};
    rightRotation(arr);
    for (auto ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << '\n';
}


