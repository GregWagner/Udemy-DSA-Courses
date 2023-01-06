#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    int count {};
    for (size_t i {}; i < s.size(); ++i) {
        if (i == 0 || s[i - 1] == s[i]) {
            ++count;
        } else {
            std::cout << s[i - 1] << count << '_';
            count = 1;
        }
    }
    std::cout << s[s.size() - 1] << count << '\n';
}