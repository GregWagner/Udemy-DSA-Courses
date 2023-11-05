/*
 * Given an integer N, print all binary strings of
 * size N without consecutive ones.
 *
 * Brute force - generate all binary strings then
 * remove the invalid ones
 */
#include <iostream>
#include <vector>

std::vector<std::string> v;

void helper(std::string str, int n, int i) {
    if (i == n) {
        v.push_back(str);
        return;
    }
    std::string s1 = str;
    s1.push_back('0');
    helper(s1, n, i + 1);

    if (i > 0 && str[i - 1] == '0') {
        str.push_back('1');
        helper(str, n, i + 1);
    } else if (i == 0) {
        str.push_back('1');
        helper(str, n, i + 1);
    }
}

std::vector<std::string> binaryStrings(int n) {
    v.clear();
    std::string str;
    helper(str, n, 0);
    return v;
}

int main() {
    auto answer = binaryStrings(3);
    for (const auto& value : answer) {
        std::cout << value << '\n';
    }
}
