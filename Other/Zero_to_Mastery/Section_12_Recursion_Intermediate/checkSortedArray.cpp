/*
 * Check if an array is sorted
 * using recursion
 */
#include <ios>
#include <iostream>

// check first 2 values then recursively check the rest
bool isSorted(int a[], int n) {
    if (n <= 1) {
        return true;
    }
    if (a[0] > a[1]) {
        return false;
    }
    return isSorted(a + 1, n - 1);
}

// recursively check the larger part then (if needed) check
// the first 2 values
bool isSorted2(int a[], int n) {
    if (n <= 1) {
        return true;
    }
    if (!isSorted(a + 1, n - 1)) {
        return false;
    }
    return a[0] <= a[1];
}

// check from right to left
bool isSorted3(int a[], int n) {
    if (n <= 1) {
        return true;
    }
    if (a[n-2] > a[n-1]) {
        return false;
    }
    return isSorted3(a, n - 1);
}

int main() {
    std::cout << std::boolalpha;

    int a[] {1, 2, 3, 4, 5};
    std::cout << isSorted(a, 5) << '\n';
    std::cout << isSorted2(a, 5) << '\n';
    std::cout << isSorted3(a, 5) << '\n';

    int b[] {1, 2, 3, 6, 5};
    std::cout << isSorted(b, 5) << '\n';
    std::cout << isSorted2(b, 5) << '\n';
    std::cout << isSorted3(b, 5) << '\n';
}
