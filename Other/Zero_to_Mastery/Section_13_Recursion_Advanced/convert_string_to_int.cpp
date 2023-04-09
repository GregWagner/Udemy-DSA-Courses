/*
 * Convert String to Integer
 */
#include <iostream>

int convert_string_to_integer(const std::string &s, int n) {
    return (n == 0 ?
            0 : 
            (convert_string_to_integer(s, n - 1) * 10) + (s[n - 1] - '0'));
}

int main() {
    std::cout << convert_string_to_integer("12345", 5) << '\n';
}
