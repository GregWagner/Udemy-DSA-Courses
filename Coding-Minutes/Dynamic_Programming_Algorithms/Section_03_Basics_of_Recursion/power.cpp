/*
 * Example 5 - Video 14
 * Write a function to find the power of a number,
 * both number and power are given as inputs.
 */
#include <iostream>

// slow O(n) space and time
int power(int a, int n) {
    // base case
    if (n == 0) {
        return 1;
    }

    // recursive case
    return a * power(a, n - 1);
}

// O(log n) space and time
int fastPower(int a, int n) {
    // base case
    if (n == 0) {
        return 1;
    }

    // recursive case
    int temp = fastPower(a, n / 2);
    temp *= temp;       // square the result
    return (n & 1 ? a * temp : temp);
}

int main() {
    std::cout << power(2, 3) << '\n';
    std::cout << fastPower(2, 3) << '\n';
}
