/*
 * Print all suffexes
 */
#include <iostream>
#include <string>

void printAllSuffixes(char s[]) {
    for (size_t start{}; s[start] != '\0'; ++start) {
        size_t index{ start };
        while (s[index] != '\0') {
            std::cout << s[index];
            ++index;
        }
        std::cout << '\n';
    }
}

int main() {
    char str[] = "abcd";
    printAllSuffixes(str);

    std::string s{ "abcd" };
    for (int i = s.size() - 1; i >= 0; --i) {
        std::cout << s.substr(i) << '\n';
    }
}
