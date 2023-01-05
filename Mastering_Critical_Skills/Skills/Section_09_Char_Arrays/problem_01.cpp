/*
 * Is Prefix?
 * Read 2 strings and print YES if the second string is a prefix for the
 * first string
 */
#include <iostream>
#include <string>

int main() {
    std::string s1 {"ABCDEFG"};
    std::string s2 {"BCDEF"};

    if (s1.size() == s2.size()) {
        std::cout << (s1 == s2 ? "YES" : "NO") << '\n';
        return 0;
    }

    if (s1.size() < s2.size()) {
        std::cout << "NO\n";
        return 0;
    }

    for (size_t i {}; i < s2.size(); ++i) {
        if (s1[i] != s2[i]) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
}