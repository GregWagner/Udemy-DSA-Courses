/*
 * Takes a sorted array of distinct integers, which is
 * rotated about a pivot and find the index of any given
 * element.
 *
 * Use modified binary search
 * Find midpoint and if
 *      a[start] < a[mid] then the midpoint is on line 1
 *      a[mid] <= a[end] then the midpoint is on line 2
 */
#include <iostream>
#include <vector>

int rotated_search(const std::vector<int>& nums, int target) {
    int start{};
    int end = nums.size() - 1;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (target == nums[middle]) {
            return middle;
        }

        if (nums[start] <= nums[middle]) {
            // mid lies on left line
            if (target >= nums[start] && target <= nums[middle]) {
                end = middle - 1; // left
            } else {
                start = middle + 1; // right
            }
        } else {
            // mid lies on right line
            if (target >= nums[middle] && target <= nums[end]) {
                start = middle + 1; // right
            } else {
                end = middle - 1; // left
            }
        }
    }
    return -1;
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a{ 7, 9, 10, 1, 2, 3, 4, 5, 6 };
    std::cout << (rotated_search(a, 4) == 6) << '\n';
}
