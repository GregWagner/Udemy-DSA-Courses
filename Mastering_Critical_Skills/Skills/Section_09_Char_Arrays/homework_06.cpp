#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    char previous_char = s[0];
    for (const auto& c : s) {
        if (c == previous_char) {
            std::cout << c;
        } else {
            std::cout << ' ' << c;
            previous_char = c;
        }
    }
    std::cout << '\n';
}