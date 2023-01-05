/*
 * Frequency
 * Ignore upper letters and compute the frequenccy of
 * lower letters
 */
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> freq(26, 0);
    std::string s {"bAAAaaazz"};

    for (const char c : s) {
        if (c >= 'a' && c <= 'z') {
            ++freq[c - 'a'];
        }
    }

    for (int i {}; i < freq.size(); ++i) {
        if (freq[i]) {
            std::cout << static_cast<char>('a' + i) << ' ' << freq[i] << '\n';
        }
    }
}