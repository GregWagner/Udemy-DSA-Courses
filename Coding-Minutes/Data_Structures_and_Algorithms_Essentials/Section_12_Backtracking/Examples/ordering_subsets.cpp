/*
 * Order by length and the alphabetically
 */
#include <algorithm>
#include <iostream>
#include <vector>

void findSubsets(char* input, char* output, std::vector<std::string>& list,
    int input_index = 0, int output_index = 0) {
    // base case
    if (input[input_index] == '\0') {
        output[output_index] = '\0';
        list.emplace_back(output);
        return;
    }

    // include the ith letter in the output
    output[output_index] = input[input_index];
    findSubsets(input, output, list, input_index + 1, output_index + 1);

    // backtracking case
    // exclude the ith letter in the output (overwrite output[output_index])
    findSubsets(input, output, list, input_index + 1, output_index);
}

int main() {
    std::vector<std::string> list;
    char output[100];
    char input[] = "abc";

    findSubsets(input, output, list);

    std::sort(begin(list), end(list), [](std::string& a, std::string& b) {
        return (a.length() == b.length() ? a < b : a.length() < b.length());
    });

    for (const auto& ele : list) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
