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
    std::string s {"bAAAaaazzz"};

    for (const char c : s) {
        if (c >= 'a' && c <= 'z') {
            ++freq[c - 'a'];
        }
    }
}