/*
 * Implement a function that takes an array as input
 * and returns the maximmum subarray sum.
 */
#include <iostream>
#include <vector>

template <typename T>
int maxSumSubarray(const std::vector<T>& a) {
    bool allNegative { true };
    int largest_sum{ a[0] };
    int current_sum {};
    for (const auto& ele : a) {
        if (ele >= 0) {
            allNegative = false;
        }
        current_sum += ele;
        if (current_sum < 0) {
            current_sum = 0;
        } else {
            largest_sum = std::max(largest_sum, current_sum);
        }
    }

    if (allNegative) {
        return *std::max_element(a.begin(), a.end());
    }
    return largest_sum;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a { 1, -2, 3, 4, 4, -2 };
    std::cout << (maxSumSubarray(a) == 11) << '\n';

    std::vector<int> b { 5, 0, -1, 0, 1, 2, -1 };
    std::cout << (maxSumSubarray(b) == 7) << '\n';
}
