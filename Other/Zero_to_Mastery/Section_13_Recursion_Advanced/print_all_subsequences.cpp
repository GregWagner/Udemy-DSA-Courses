/*
 * Print all subsequences of string
 */
#include <iostream>
#include <string>

void printAllSubsequeces(std::string input, std::string output) {
    // base case
    if (input.empty()) {
        std::cout << output << '\n';
        return;
    }

    // exclude character in output
    printAllSubsequeces(input.substr(1), output);

    // include character in output
    printAllSubsequeces(input.substr(1), output + input[0]);
}

void printAllSubsequeces(char *input, char *output, int i = 0) {
    if (input[0] == '\0') {
        output[i] = '\0';
        std::cout << output << '\n';
        return; 
    }

    output[i] = input[0];

    // exclude character in output
    printAllSubsequeces(input + 1, output, i);

    // include character in output
    printAllSubsequeces(input + 1, output, i + 1);
}

int main() {
    std::string s1 {"abc"};
    std::string s2;
    printAllSubsequeces(s1, s2);
}
