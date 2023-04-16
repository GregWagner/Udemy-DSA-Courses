#include <iostream>

auto sum(int arr[], int len) -> int {
    if (len == 1) {
        return arr[0];
    }

    return arr[len - 1] + sum(arr, len - 1);
}

auto main() -> int {
    int a[] { 1, 8, 2, 10, 3 };
    std::cout << std::boolalpha << (sum(a, 5) == 24) << '\n';
}