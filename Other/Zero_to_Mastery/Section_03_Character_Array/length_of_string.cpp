/*
 * Calculates the length of a character array
 */
#include <iostream>

size_t length (char input[]) {
    size_t size {};
    for (size_t i {}; input[i] != '\0'; ++i) {
        ++size;
    }
    return size;
}

int main() {
    size_t const SIZE {100};

    char s[SIZE];
    std::cout << "Enter a string: ";
    std::cin >> s;

    std::cout << "The length is " << length(s) << '\n';
}
