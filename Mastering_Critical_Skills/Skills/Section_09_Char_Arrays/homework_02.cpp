#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    std::cout << "Enter 2 strings: ";
    std::cin >> s1 >> s2;

    if (s1.size() < s2.size()) {
        std::cout << "NO\n";
        return 0;
    }

    bool is_suffix { true };
    size_t s1_index = s1.size() - s2.size();
    for (size_t i {}; i < s2.size(); ++i) {
        if (s1[s1_index++] != s2[i]) {
            is_suffix = false;
        }
    }
    std::cout << (is_suffix ? "YES\n" : "NO\n");
}