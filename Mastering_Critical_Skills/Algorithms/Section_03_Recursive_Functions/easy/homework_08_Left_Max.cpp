#include <iostream>

auto left_max(int arr[], int len) -> void {
    if (len == 1) {
        return;
    }
    left_max(arr, len - 1);
    arr[len - 1] = std::max(arr[len - 1], arr[len - 2]);
}

auto main() -> int {
    int a[] { 1, 3, 5, 7, 4, 2 };
    left_max(a, 7);
    for (int i {}; i < 6; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}