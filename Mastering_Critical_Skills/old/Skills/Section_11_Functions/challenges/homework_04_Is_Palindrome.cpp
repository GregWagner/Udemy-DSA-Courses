#include <iostream>
#include <vector>

auto isPalindrome(const std::vector<int>& a) -> bool {
    size_t start {};
    size_t end { a.size() - 1 };
    while (start < end) {
        if (a[start] != a[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

auto main() -> int {
    std::cout << "Enter size: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n);
    std::cout << "Enter " << n << " numbers: ";
    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << "This" << (isPalindrome(a) ? " is " : " is not ")
              << "a palindrome\n";
}