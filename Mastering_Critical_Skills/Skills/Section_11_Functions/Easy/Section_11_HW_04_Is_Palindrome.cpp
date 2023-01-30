#include <iostream>

auto is_palindrome(int* a, int n) {
    int start {};
    int end { n - 1 };
    while (start < end) {
        if (a[start++] != a[end--]) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    int n {};
    std::cout << "Enter n: ";
    std::cin >> n;

    int a[101];
    for (int i {}; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << (is_palindrome(a, n) ? "Is a Palindrome\n"
                                      : "Is Not a Aplindrome\n");
}