#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n);

    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    int start {};
    int end { n - 1 };
    bool isPalindrome { true };
    while (start < end) {
        if (a[start] != a[end]) {
            isPalindrome = false;
            break;
        }
        ++start;
        --end;
    }
    std::cout << (isPalindrome ? "YES" : "NO") << '\n';
}