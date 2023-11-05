/*
 * Check if an element is present
 */
#include <ios>
#include <iostream>

bool isElementPresent(int a[], int n, int key) {
    if (n == 0) {
        return false;
    }
    if (a[0] == key) {
        return true;
    }
    return isElementPresent(a + 1, n - 1, key);
}

int main() {
    std::cout << std::boolalpha;

    int a[] {1, 3, 5, 7, 9};
    std::cout << isElementPresent(a, 5, 5) << '\n';
}
