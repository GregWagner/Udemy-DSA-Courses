#include <vector>
#include <iostream>

auto rightRotation(std::vector<int>& arr) {
    int last {arr[arr.size() - 1]};
    for (size_t i {arr.size() - 1}; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}


auto rightRotationWithSteps(std::vector<int>& arr, int steps) {
    steps = steps % arr.size();
    for (int i {0}; i < steps; ++i) {
        rightRotation(arr);
    }
}

auto main()-> int {
    std::vector<int> arr {1, 2, 3, 4, 5};
    rightRotationWithSteps(arr, 2);
    for (auto ele : arr) {
        std::cout << ele << " ";
    }
    std::cout << '\n';
}
