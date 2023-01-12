/*
 * Find most frequent number
 * See his solution - he did a frequency array
 * but shifted everything by 270 so everything is
 * positive.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

int most_frequent(const std::vector<int> &a) {
    std::unordered_map<int, int> freq;
    int maxCount {};
    int maxValue {};
    for (int i {}; i < a.size(); ++i) {
        if (freq.count(a[i])) {
            ++freq[a[i]];
        } else {
            freq[a[i]] = 1;
        }
        if (freq[a[i]] > maxCount) {
            maxCount = freq[a[i]];
            maxValue = a[i];
        }
    }
    return maxValue;
}

int main() {
    std::vector<int> a {-1, 2, -1, 3, -1, 5, 5};
    std::cout << std::boolalpha << (most_frequent(a) == -1) << '\n';
}