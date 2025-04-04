/*
 * Store all positions of an element
 */
#include <iostream>
#include <vector>

void storeAllPositions(const std::vector<int> &a, int key,
        std::vector<int> &answer, size_t i = 0) {
    if (i == a.size()) {
        return;
    }
    if (a[i] == key) {
        answer.push_back(i);
    }
    storeAllPositions(a, key, answer, i + 1);
}

int main() {
    std::vector<int> a {5, 6, 5, 6, 6};
    std::vector<int> answer;
    storeAllPositions(a, 5, answer);
    for (const auto &e : answer) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
