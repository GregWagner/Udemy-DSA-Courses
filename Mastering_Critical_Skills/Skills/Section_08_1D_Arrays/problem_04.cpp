/*
 * Is Palindrom
 * Determine if the array is a palindrome or not
 */
#include <iostream>
#include <vector>

bool isPalindrome(const std::vector<int>& a) {
    size_t start {};
    size_t last { a.size() - 1 };
    while (start < last) {
        if (a[start] != a[last]) {
            return false;
        }
        ++start;
        --last;
    }
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a { 1, 3, 2, 3, 1 };
    std::cout << (isPalindrome(a)) << '\n';
    std::vector<int> b { 1, 2, 3, 4 };
    std::cout << (!isPalindrome(b)) << '\n';
}