/*
 * Find the largest sum of all the subarrays
 */
#include <iostream>
#include <vector>

// Brute Force O(n^3)
template <typename T>
int largestSubArraySum1(const std::vector<T>& a) {
    int largest_sum {};
    for (size_t starting_index {}; starting_index < a.size(); ++starting_index) {
        for (size_t ending_index { starting_index }; ending_index < a.size(); ++ending_index) {
            int subarray_sum {};
            for (size_t index { starting_index }; index < ending_index; ++index) {
                subarray_sum += a[index];
            }
            largest_sum = std::max(largest_sum, subarray_sum);
        }
    }
    return largest_sum;
}

// Prefix Sum O(n^2)
/*
 * Create a new prefix array with the sums of all the elements
 * input        1 2 4 -2 3
 * prefix       1 3 7  5 8
 * The sub array sum from i to j is prefix[j] - prefix[i - i]
 */
template <typename T>
int largestSubArraySum2(const std::vector<T>& a) {
    // precompute the prefix sum vector which is the sum of all the revious elements
    std::vector<T> prefix;
    prefix.reserve(a.size());
    prefix[0] = a[0];
    for (size_t i { 1 }; i < a.size(); ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // now compute the largest sum using the prefix sum array
    int largest_sum {};
    for (size_t starting_index {}; starting_index < a.size(); ++starting_index) {
        for (size_t ending_index { starting_index }; ending_index < a.size(); ++ending_index) {
            // check for > 0 needed to avoid prefix index of -1
            int subarray_sum = (starting_index > 0 ? prefix[ending_index] - prefix[starting_index - 1] : prefix[ending_index]);
            largest_sum = std::max(largest_sum, subarray_sum);
        }
    }
    return largest_sum;
}

/*
 * Kadane's Algorithm O(n)
 * Note: THis implementation does not handle all negaative numbers
 * input        -2 3 4 -1 5 -12 6 1 3
 * Maintain a running sum and if running sum is negative reset to zero
 * current_sum  0  3 7  6 11 0  6  7  10
 * maxSum       0  3 7  7 11 11 11 11 11
 */
template <typename T>
int largestSubArraySum3(const std::vector<T>& a) {
    int largest_sum {};
    int current_sum {};
    for (const auto& ele : a) {
        current_sum += ele;
        if (current_sum > 0) {
            largest_sum = std::max(largest_sum, current_sum);
        } else {
            current_sum = 0;
        }
    }
    return largest_sum;
}

int main() {
    std::vector<int> a { -2, 3, 4, -1, 5, -12, 6, 1, 3 };
    std::cout << largestSubArraySum1(a) << '\n';
    std::cout << largestSubArraySum2(a) << '\n';
    std::cout << largestSubArraySum3(a) << '\n';
}
