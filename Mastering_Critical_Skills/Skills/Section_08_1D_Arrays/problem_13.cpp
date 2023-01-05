/*
 * Fixed Sliding window
 * Find the sub-array (consecutive numbers) of k elements that
 * has the maximum sum.
 * hint: use sliding window
 */
#include <iostream>
#include <vector>

void find_max_subarray(const std::vector<int> &a, int k) {
    int index {};
    int maxIndex {};
    int max {};
    // add up the first k values
    for (int i {}; i < k; ++i) {
        max += a[i];
    }

    int current {max};
    while (index + k < a.size()) {
        current -= a[index];        // remove the element before
        current += a[index + k];    // add the element after
        if (current > max) {
            max = current;
            maxIndex = index + 1;
        }
        ++index;
    }
    std::cout << "Index: " << maxIndex << ", Sum: "
        << max << '\n';
    for (size_t i = maxIndex; i < maxIndex + k; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a {1, 0, 3, -4, 2, -6, 9};
    find_max_subarray(a, 3);
}