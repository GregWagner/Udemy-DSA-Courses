/*
 * Conc Strings
 * Read two strings and print a new string that
 * 1) The first letter of the first string followed by the first letter
 *    of the second string
 * 2) The second letter of the first string followed by the second letter
 *    of the second string
 * 3) and so on...
 *
 * Don't create new strings
 */
#include <iostream>
#include <string>

int main() {
    std::string s1 = "abc";
    std::string s2 = "defghi";

    int s1_index {};
    int s2_index {};

    while (s1_index < s1.size() && s2_index < s2.size()) {
        std::cout << s1[s1_index] << s2[s2_index];
        ++s1_index;
        ++s2_index;
    }
    while (s1_index < s1.size()) {
        std::cout << s1[s1_index];
        ++s1_index;
    }
    while (s2_index < s2.size()) {
        std::cout << s2[s2_index];
        ++s2_index;
    }
    std::cout << '\n';
}
