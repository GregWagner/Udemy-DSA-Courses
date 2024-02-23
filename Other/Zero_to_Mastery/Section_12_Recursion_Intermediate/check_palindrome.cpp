/*
 * Check Palindrome
 */
#include <iostream>
#include <vector>

bool checkPalindrom(const std::vector<int> &a, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (a[start] != a[end]) {
        return false;
    }
    return checkPalindrom(a, start + 1, end - 1);
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {1, 2, 3, 3, 2, 1};
    std::cout << (checkPalindrom(a, 0, a.size() - 1) == true) << '\n';
    std::vector<int> b {1, 2, 3, 2, 1};
    std::cout << (checkPalindrom(b, 0, b.size() - 1) == true) << '\n';
    std::vector<int> c {1, 2, 3, 4, 2, 1};
    std::cout << (checkPalindrom(c, 0, c.size() - 1) == false) << '\n';
}
