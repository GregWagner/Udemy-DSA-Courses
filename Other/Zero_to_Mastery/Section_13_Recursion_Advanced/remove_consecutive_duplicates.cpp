/*
 * Remove Consecutive Duplicates
 */
#include <iostream>

void remove_consecutive_dups(char *s) {
    if (s[0] == '\0') {
        return;
    }
    if (s[0] == s[1]) {
        // shift the rest of the array down
        for (int i {1}; s[i] != '\0'; ++i) {
            s[i] = s[i + 1];
        }
        remove_consecutive_dups(s);
    } else {
        remove_consecutive_dups(s + 1);
    }
}

int main() {
    char s[100] = "aabbccde";
    remove_consecutive_dups(s);
    std::cout << s << '\n';
}
