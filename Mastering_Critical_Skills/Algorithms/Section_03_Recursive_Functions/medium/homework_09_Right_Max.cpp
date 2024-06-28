// this is not correct

#include <iostream>

auto right_max(int arr[], int len, int start_position=0) -> void {
    if (len == 1) {
        return;
    }
    arr[len - 1] = std::max(arr[len - 1], arr[len - 2]);
    right_max(arr, len - 1, start_position + 1);
}

auto main() -> int {
    int a[] { 1, 3, 5, 7, 4, 2 };
    right_max(a, 7);
    for (int i {}; i < 6; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}