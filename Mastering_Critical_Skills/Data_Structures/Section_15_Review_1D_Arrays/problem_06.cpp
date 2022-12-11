/*
 * Find the 3 minimum values
 */
#include <climits>
#include <iostream>
#include <vector>

std::vector<int> find_three_min_values(const std::vector<int>& a) {
    std::vector<int> answer(3, INT_MAX);
    for (const int& ele : a) {
        if (ele < answer[0]) {
            answer[2] = answer[1];
            answer[1] = answer[0];
            answer[0] = ele;
        } else if (ele < answer[1]) {
            answer[2] = answer[1];
            answer[1] = ele;
        } else if (ele < answer[2]) {
            answer[2] = ele;
        }
    }
    return answer;
}

int main() {
    std::vector<int> a { 4, 1, 3, 10, 8 };
    auto answer = find_three_min_values(a);
    std::cout << answer[0] << ", " << answer[1] << ", " << answer[2] << '\n';

    std::vector<int> b { 7, 9, -2 };
    answer = find_three_min_values(b);
    std::cout << answer[0] << ", " << answer[1] << ", " << answer[2] << '\n';
}
