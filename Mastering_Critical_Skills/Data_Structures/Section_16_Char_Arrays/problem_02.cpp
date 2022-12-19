/*
 * Is Suffix?
 * Read 2 strings and print YES if the second string is a suffix for the
 * first string
 */
#include <iostream>
#include <string>

int main() {
    std::string s1{"ABCDEFG"};
    std::string s2{"EFG"};

    if (s1.size() == s2.size()) {
        std::cout << (s1 == s2 ? "YES" : "NO") << '\n';
        return 0;
    }

    if (s1.size() < s2.size()) {
        std::cout << "NO\n";
        return 0;
    }

    size_t s1_index {s1.size() - 1};
    size_t s2_index {s2.size() - 1};
    while (s2.size()) {
        if (s1[s1_index] != s2[s2_index]) {
            std::cout << "NO\n";
            return 0;
        }
        --s1_index;
        --s2_index;
    }
    std::cout << "YES\n";
}