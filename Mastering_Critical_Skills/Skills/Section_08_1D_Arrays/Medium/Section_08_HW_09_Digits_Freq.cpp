/*
 * Digits frequency
 * For all digits from 0 to 9, we want to know how many times
 * it appears
 */
#include <iostream>
#include <vector>

void digits_freq(const std::vector<int> &a) {
    std::vector<int> answer(10, 0);
    for (int value : a) {
        if (value == 0) {
            ++answer[0];
        }
        while (value) {
            ++answer[value % 10];
            value /= 10;
        }
    }

    for (size_t i {}; i < answer.size(); ++i) {
        if (answer[i]) {
            std::cout << "The value " << i << " appeared "
                << answer[i] << " times.\n";
        }
    }
}

int main() {
    std::vector<int> a {0, 78, 307};
    digits_freq(a);
}