#include <iostream>

auto average(int arr[], int len) -> double {
    if (len == 1) {
        return arr[0];
    }

    double currentAverage { average(arr, len - 1) };

    // currentSum is the averge of len -1 so sum / (len - 1)

    // restore just the sum
    double currentSum { currentAverage * (len - 1) };

    return (currentSum + arr[len - 1]) / len;
}

auto main() -> int {
    int a[] { 1, 8, 2, 10, 3 };
    std::cout << std::boolalpha << (average(a, 5) == 4.8) << '\n';
}