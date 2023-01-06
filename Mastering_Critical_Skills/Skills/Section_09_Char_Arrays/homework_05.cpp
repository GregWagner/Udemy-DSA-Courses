#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a number (up to 6 digits): ";
    std::cin >> s;

    int n {};
    for (size_t index {}; index < s.size(); ++index) {
        int digit = s[index] - '0';
        n *= 10;
        n += digit;
    }

    std::cout << n << ' ' << n * 3 << '\n';
}