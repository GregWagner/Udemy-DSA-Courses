#include <iostream>
#include <vector>

size_t missingNumber(std::vector<int> arr) {
    size_t n = arr.size() + 1;
    size_t sum = n * (n + 1) / 2;
    // std::cout << "Sum: " << sum << '\n';
    for (size_t i = 0; i <= arr.size() - 1; i++) {
        sum -= static_cast<int>(arr[i]);
        // std::cout << "Sum: " << sum << '\n';
    }
    return sum;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> arr(n - 1, 0);
    for (size_t i = 0; i < n - 1; i++) {
        std::cin >> arr[i];
    }
    std::cout << missingNumber(arr) << '\n';
}
