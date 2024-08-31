#include <iostream>

auto accumulate_arr(int arr[], int len) -> void {
    if (len == 1) {
        return;
    }
    accumulate_arr(arr, len - 1);
    arr[len - 1] += arr[len - 2];
}

auto main() -> int {
    int a[] { 1, 8, 2, 10, 3 };
    accumulate_arr(a, 5);
    for (int i {}; i < 5; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}