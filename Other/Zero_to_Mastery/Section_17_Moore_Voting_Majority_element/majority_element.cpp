/*
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋
 * times. You may assume that the majority element always exists in the
 * array.
 *
 * Leet code 169
 *
 * Brute-Force method (O(n^2))
 * Starting at the first element get the number of that element in 
 * the array. If > than n/2 that is the answer. Otherwise, repeat
 * for each element until the correct one found.
 *
 * Hashmap (O(n))
 * Keep track of element, count then iterate over hashmap to find
 * the largest
 *
 * Sorting  (O(nlog(n)))
 * Sort the array and return the middle element
 *
 * Voting approach O(n)
 * Assumme first elememt is the answer and set count to 1
 * Go through each element in array.
 * - if element same, increment count
 * - if different, decrement count, If count is zero, change
 *   candiate to this element.
 */
#include <iostream>
#include <vector>
#include <algorithm>

// Moore's Voing Approach (O(n))
int majorityElement(std::vector<int>& nums) {
    int candidate {nums[0]}; 
    int count {1};
    for (size_t i {1}; i < nums.size(); ++i) {
        if (candidate == nums[i]) {
            ++count;
        } else {
            --count;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    // if you can't assume that the majority element exists
    size_t count2 {};
    for (size_t i {}; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
            ++count2;
        }
    }
    if (count2 > nums.size() / 2) {
        return candidate;
    }
    return -1;
}

// sort approach
int majorityElement1(std::vector<int>& nums) {
    std::sort(std::begin(nums), std::end(nums));
    return nums[(nums.size() - 1) / 2];
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {3, 2, 3};
    std::cout << (majorityElement(a) == 3) << '\n';

    std::vector<int> b {2, 2, 1, 1, 1, 2, 2};
    std::cout << (majorityElement(b) == 2) << '\n';

    std::vector<int> c {3, 3, 4};
    std::cout << (majorityElement(c) == 3) << '\n';
}
