/*
 * Find the first and last position of an element
 * in a sorted array.
 * Leetcode 34
 *
 * Do a initial binary search to find a position of the
 * element - note this may not be the first or last
 *
 * Do another binary search with end = mid - 1 and repeat
 * until item not found. The first position will be the last 
 * successful binary search.
 *
 * Do another binary search with start = mid + 1 and repeat
 * until item not found. The last position will be the last 
 * successful binary search.
 */
#include <iostream>
#include <vector>

template <typename T>
int binarySearch(const std::vector<T>& a, T target) {
    int start {};
    int end = a.size() - 1;
    while (start <= end) {
        // note - better than (s + e)/2 since no overflow
        int middle = start + (end - start) / 2;
        if (a[middle] == target) {
            return middle;
        }
        if (a[middle] > target) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}

template <typename T>
int getIndex(const std::vector<T>& nums, T target, bool getFirst) {
    int start {};
    int end = nums.size() - 1;
    int answer {-1};
    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (nums[middle] == target) {
            answer = middle;
            if (getFirst) {
                end = middle - 1;   // search left hand size for first
            } else {
                start = middle + 1; // search right hand size for last
            }
        } else if (nums[middle] < target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return answer;
}

template <typename T>
std::vector<int> searchRange1(const std::vector<T>& nums, T target) {
    std::vector<int> v(2, -1);
    v[0] = getIndex(nums, target, true);
    if (v[0] == -1) {
        return v;
    }
    v[1] = getIndex(nums, target, false);
    return v;
}

template <typename T>
std::vector<int> searchRange(const std::vector<T>& nums, T target) {
    int result = binarySearch(nums, target);
    if (result == -1) {
        return {-1, -1};
    }

    int start {result};
    while (start >= 1 && nums[start - 1] == target) {
        --start;
    }
    int end {result};
    while (end < nums.size() - 1 && nums[end + 1] == target) {
        ++end;
    }
    return {start, end};;
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a {5, 7, 7, 8, 8, 10};
    auto answer = searchRange1(a, 8);
    std::cout << (answer[0] == 3 && answer[1] == 4) << '\n';

    answer = searchRange1(a, 6);
    std::cout << (answer[0] == -1 && answer[1] == -1) << '\n';

    answer = searchRange1(a, 5);
    std::cout << (answer[0] == 0 && answer[1] == 0) << '\n';

    answer = searchRange1(a, 10);
    std::cout << (answer[0] == 5 && answer[1] == 5) << '\n';

    std::vector<int> b {};
    answer = searchRange1(b, 10);
    std::cout << (answer[0] == -1 && answer[1] == -1) << '\n';
}
