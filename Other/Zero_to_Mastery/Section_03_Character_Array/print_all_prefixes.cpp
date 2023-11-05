/*
 * Print all prefixes
 * Starting index is 0 and ending index starts at 0 and
 * goes to the end of the string
 */
#include <iostream>
#include <string>

void printAllPrefixs(char s[]) {
    for (size_t end {}; s[end] != '\0'; ++end) {
        for (size_t index {}; index <= end; ++index) {
            std::cout << s[index];
        }
        std::cout << '\n';
    }
}

int main() {
    char str[] = "abcd";
    printAllPrefixs(str);
#if 0
    std::string s{"abcd"};
    for (size_t i {1}; i <= s.size(); ++i) {
        std::cout << s.substr(0, i) << '\n';
    }
#endif
}
