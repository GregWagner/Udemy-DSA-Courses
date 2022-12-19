/*
 * Special String Mapping
 * For each letter in a string:
 * 1) If upper case, don't change it
 * 2) If lower case, use this map of 26 characters::
 *     YZIMNESTODUAPWXHQFBRJKCGVL
 * 3) If it is a digit use this map
 *      0123456789
 *      !@#$%^&*()
 */
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string character_map {"YZIMNESTODUAPWXHQFBRJKCGVL"};
    std::string number_map {"!@#$%^&*()"};
    std::string s {"vwXYZ0123"};
    for (size_t i {}; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = character_map[s[i] - 'a'];
        } else if (s[i] >= '0' && s[i] <= '9') {
            s[i] = number_map[s[i] - '0'];
        }
    }
    std::cout << s << '\n';
}