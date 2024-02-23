/*
 * Sum of natural numbers using recursion
 */
#include <iostream>

/* Time O(1) and Space O(1) */
int betterSum(int n) {
    return n * ( n + 1 ) / 2;
}

/* Time O(n) and Space O(1) */
int sumIter(int n) {
    int sum {};
    for (int i {1}; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

/* Time O(n) but Space O(n) */
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return sum(n - 1) + n;
}

int main() {
    int input {};
    std::cin >> input;
    std::cout << sum(input) << '\n';
    std::cout << betterSum(input) << '\n';
    std::cout << sumIter(input) << '\n';
}
