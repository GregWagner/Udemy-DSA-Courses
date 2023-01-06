#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    std::cout << "Enter 2 strings: ";
    std::cin >> s1 >> s2;

    size_t ending_index = std::max(s1.size(), s2.size());
    for (size_t i {}; i < ending_index; ++i) {
        if (i >= s1.size()) {
            std::cout << "YES\n";
            return 0;
        }

        if (i <= s2.size() || s1[i] > s2[i]) {
            std::cout << "NO\n";
            return 0;
        }
    }
}