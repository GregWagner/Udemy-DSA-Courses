/*
 * Search in rotated sorted array
 * See also Video 102 in DS Essential Course
 *
 * Leetcode 33
 */

#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int start {};
    int end = nums.size() -1;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (target == nums[middle]) {
            return middle;
        }

        if (nums[start] <= nums[middle]) {
            if (target >= nums[start] && target < nums[middle]) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        } else {
            if (target > nums[middle] && target <= nums[end]) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
    }
    return -1;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {4,5,6,7,0,1,2};
    std::cout << (search(a, 0) == 4) << '\n';
    std::cout << (search(a, 3) == -1) << '\n';

    std::vector<int> b {1};
    std::cout << (search(b, 0) == -1) << '\n';

    std::vector<int> c {1, 3, 5};
    std::cout << (search(c, 1) == 0) << '\n';

    std::vector<int> d {5, 1, 3};
    std::cout << (search(d, 3) == 2) << '\n';
}
