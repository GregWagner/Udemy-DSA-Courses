/*
 * Is Palindrome
 * Determine if the array is a palindrome or not
 */
#include <iostream>
#include <vector>

auto isPalindrome(const std::vector<int>& a) -> bool {
    size_t start {};
    size_t last { a.size() - 1 };
    while (start < last) {
        if (a[start] != a[last]) {
            std::cout << "NO\n";
            return false;
        }
        ++start;
        --last;
    }
    std::cout << "YES\n";
    return true;
}

auto main() -> int {
    std::cout << std::boolalpha;
    std::vector<int> a { 1, 3, 2, 3, 1 };
    std::cout << (isPalindrome(a)) << '\n';
    std::vector<int> b { 1, 2, 3, 4 };
    std::cout << (!isPalindrome(b)) << '\n';
}