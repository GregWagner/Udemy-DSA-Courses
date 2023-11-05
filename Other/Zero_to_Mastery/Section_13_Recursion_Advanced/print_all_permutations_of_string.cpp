/*
 * Print all permutations of a string
 * ABC
 * ---
 *  ABC
 *  ACB
 *  BAC
 *  BCA
 *  CAB
 *  CBA
 *
 * Note: the ouput will be length different strings
 */
#include <iostream>

void printPermutataion(char *s, int index = 0) {
    if (s[index] == '\0') {
        std::cout << s << '\n';
        return;
    }
    for (int i {index}; s[i] != '\0'; ++i) {
        std::swap(s[i], s[index]);
        printPermutataion(s, index + 1);
        std::swap(s[i], s[index]);
    }
}

int main() {
    char s[100] = "abcd";
    printPermutataion(s);
}
