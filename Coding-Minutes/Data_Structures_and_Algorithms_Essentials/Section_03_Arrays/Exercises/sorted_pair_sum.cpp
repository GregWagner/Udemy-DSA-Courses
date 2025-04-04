/*
 * This is an exercise
 * Given a sorted array and a number, find a pair in the
 * array whose sum is closest to x.
 */
#include <climits>
#include <iostream>
#include <vector>

 // brute force (check all pairs)
std::pair<int, int> closestSum1(const std::vector<int>& arr, int x) {
    int difference{ INT_MAX };
    int first{};
    int second{};
    for (size_t i{}; i < arr.size(); ++i) {
        for (size_t j{ i + 1 }; j < arr.size(); ++j) {
            int sum{ arr[i] + arr[j] };
            if (std::abs(sum - x) < difference) {
                difference = std::abs(sum - x);
                first = i;
                second = j;
            }
        }
    }
    return { arr[first], arr[second] };
}

// two pointer
std::pair<int, int> closestSum(const std::vector<int>& arr, int x) {
    int difference{ INT_MAX };
    int first{};
    int second{};

    int left{};
    int right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (std::abs(sum - x) < difference) {
            difference = std::abs(sum - x);
            first = left;
            second = right;
        }
        // try to minimize the difference
        if (sum < x) {
            ++left;     // increase sum
        } else {
            --right;    // decrease sum
        }
    }
    return { arr[first], arr[second] };
}

int main() {
    std::cout << std::boolalpha;

    std::vector<int> a = { 10, 22, 28, 29, 30, 40 };
    auto answer = closestSum(a, 54);
    std::cout << answer.first << ", " << answer.second << '\n';
    std::cout << (answer.first == 22 && answer.second == 30) << '\n';
}
