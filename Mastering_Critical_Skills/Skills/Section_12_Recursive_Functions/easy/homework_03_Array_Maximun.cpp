#include <iostream>

auto arr_max(int arr[], int len) {
    if (len == 1) {
        return arr[0];
    }
    int max = arr_max(arr, len - 1);
    return std::max(max, arr[len - 1]);
}

auto main() -> int {
    std::cout << std::boolalpha;

    int a[] { 1, 8, 2, 10, 3 };
    std::cout << (arr_max(a, 5) == 10) << '\n';

    int b[] { 1, 8, 2, 10, 30 };
    std::cout << (arr_max(b, 5) == 30) << '\n';

    int c[] { 100, 8, 2, 10, 30 };
    std::cout << (arr_max(c, 5) == 100) << '\n';
}