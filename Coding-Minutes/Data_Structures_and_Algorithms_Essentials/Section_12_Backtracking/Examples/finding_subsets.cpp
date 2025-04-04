/*
 * Given a string, find all subsets (i.e. subsequence not substring)
 * of the given string.
 *
 * Brute force requires 2 recursive calls
 *
 * input  abc
 * output "", a, b, c, ab, ac, bc, abc
 *
 * for each character
 * Include the character and exclude the character
 */
#include <iostream>

void findSubsets(char* input, char* output, int input_index = 0, int output_index = 0) {
    // base case
    if (input[input_index] == '\0') {
        output[output_index] = '\0';
        std::cout << output << '\n';
        return;
    }

    // recursive cases
    // include the ith letter in the output so move the
    // index for both the input and output arrays
    output[output_index] = input[input_index];
    findSubsets(input, output, input_index + 1,
        output_index + 1);

    // backtracking step
    // exclude the ith letter in the output (overwrite
    // output[output_index])
    findSubsets(input, output, input_index + 1,
        output_index);
}

int main() {
    char output[100];
    char input[] = "abc";

    findSubsets(input, output);
}
