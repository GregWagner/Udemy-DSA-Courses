#include <iostream>

auto array_increment(int arr[], int len) -> void {
    if (len == 1) {
        std::cout << arr[0] << ' ';
        return;
    }

    array_increment(arr, len - 1);
    std::cout << arr[len - 1] + len - 1 << ' ';
}

auto main() -> int {
    int a[] { 1, 2, 5, 9 };
    array_increment(a, 4);
    std::cout << '\n';

    int b[] { 1, 8, 2, 10, 3 };
    array_increment(b, 5);
    std::cout << '\n';
}