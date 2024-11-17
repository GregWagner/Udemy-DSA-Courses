/*
 * This is an exercise
 * Given an integer, vector, and a value k, rotate the array
 * k times clockwise;
 */
#include <iostream>
#include <vector>
#include <algorithm>

// most optimized way to do this
// First reverse the part from 0 to k - 1
// Then reverse the part from k to end
// Then reverse the whole thing
std::vector<int> kRotate2(std::vector<int> &a, int k) {
    std::reverse(a.begin(), a.begin() + a.size() - k);
    std::reverse(a.begin() + a.size() - k, a.end());
    std::reverse(a.begin(), a.end());
    return a;
}

// using extra space
std::vector<int> kRotate1(const std::vector<int>& a, int k) {
    k %= a.size();
    std::vector<int> answer;
    size_t n { a.size() };
    for (size_t i{ n - k }; i < n; ++i) {
        answer.push_back(a[i]);
    }
    for (size_t i{}; i < n - k; ++i) {
        answer.push_back(a[i]);
    }
    return answer;
}

std::vector<int> kRotate(const std::vector<int>& a, int k) {
    std::vector<int> answer(a.size());
    for (size_t i {}; i < a.size(); ++i) {
        int new_index = (i + k) % a.size();
        //      std::cout << "Moving " << i  << " to " << new_index << '\n';
        answer[new_index] = a[i];
    }
    return answer;
}

void print(const std::vector<int>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a { 1, 3, 5, 7, 9 };
    auto answer = kRotate(a, 2);
    print(answer);

    std::vector<int> b{ 1, 3, 5, 7, 9 };
    answer = kRotate1(b, 2);
    print(answer);

    std::vector<int> c{ 1, 3, 5, 7, 9 };
    answer = kRotate2(c, 2);
    print(answer);
}
