/*
 * Sum of Array
 */
#include <iostream>

// from right to left
int sumOfArray(int a[], int n) {
    if (n == 0) {
        return 0;
    }
    return a[n-1] + sumOfArray(a, n - 1);
}

// from left to right
int sumOfArray2(int a[], int n) {
    if (n == 0) {
        return 0;
    }
    return a[0] + sumOfArray(a + 1, n - 1);
}

int main() {
    int a[] {1, 2, 3, 4, 5};
    std::cout << sumOfArray(a, 5) << '\n';
    std::cout << sumOfArray2(a, 5) << '\n';
}
