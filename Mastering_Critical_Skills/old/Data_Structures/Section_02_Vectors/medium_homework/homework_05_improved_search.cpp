#include <iostream>
#include <vector>

auto improvedSearch(std::vector<int>& arr, int val) -> int {
    for (size_t i {0}; i < arr.size(); ++i) {
        if (arr[i] == val) {
            if (i != 0) {
                std::swap(arr[i], arr[i - 1]);
            }
            return arr[i];
        }
    }
    return -1;
}

auto main() -> int {
    std::vector<int> arr {1, 2, 3, 4, 5};
    std::cout << improvedSearch(arr, 4) << '\n';
    return 0;
}
