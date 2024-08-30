/*
 * leet code 58
 */
#include <string>
#include <iostream>
int length(std::string& word) {
    if (word.size() == 0) {
        return 0;
    }
    size_t count{};

    for (size_t i { word.size() - 1 }; i >= 0; --i) {
        if (word[i] != ' ') {
            ++count;
        } else {
            // white space. Check if we have found a word
            if (i == 0 || count) {
                return count;
            }
        }
    }
    return count;
}

int length_slow(std::string& word) {
    size_t count {};
    size_t i {};
    size_t n = word.size();
    while (i < n) {
        if (word[i] == ' ') {
            while (i < n && word[i] == ' ') {
                ++i;
            }
            if (i < n) {
                count = 0;
            } else {
                // we reached the end of the string
                return count;
            }
        } else {
            ++i;
            ++count;
        }
    }
    return count;
}

int main() {
    std::cout << std::boolalpha;
    std::string s {"Hello World"};
    std::cout << (length(s) == 5) << '\n';
    std::string s1 {};
    std::cout << (length(s1) == 0) << '\n';
    std::string s2 {"     Hello    World    "};
    std::cout << (length(s2) == 5) << '\n';
    std::string s3 {"a"};
    std::cout << (length(s3) == 1) << '\n';
}
