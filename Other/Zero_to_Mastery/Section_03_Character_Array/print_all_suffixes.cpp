/*
 * Print all suffexes
 */
#include <iostream>
#include <string>

int main() {
    std::string s{"abcd"};
    for (int i = s.size() - 1; i >= 0; --i) {
        std::cout << s.substr(i) << '\n';
    }
}
