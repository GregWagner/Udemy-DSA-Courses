/*
 * Calculate the factorial of a nuumber
 * n! = 1 * 2 * 3 * ... * (n - 1) * n
 */
#include <iostream>

/* Time O(n) and Space O(1) */
long factorial_iter(long n) {
    long results {1};
    for (int i {1}; i <= n; ++i) {
        results *= i;
    }
    return results;
}

/* Time O(n) and Space O(n) */
long factorial(long n) {
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1) * n;

}

int main() {
    int input {};
    std::cin >> input;
    std::cout << factorial(input) << '\n';
    std::cout << factorial_iter(input) << '\n';
}
