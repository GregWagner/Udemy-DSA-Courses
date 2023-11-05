#include <iostream>

bool isSorted(int a[], int n) {
    if (n <= 1) {
        return true;
    }
    return a[0] < a[1] && isSorted(a + 1, n - 1);
}

bool isSorted2(int a[], int i, int n) {
    if (i == n - 1) {
        return true;;
    }
    return (a[i] < a[i + 1]) && isSorted2(a, i + 1, n);
}

int main() {
    std::cout << std::boolalpha;
    int a[] {1, 3, 5, 7};
    std::cout << (isSorted(a, 4)) << '\n';
    std::cout << (isSorted2(a, 0, 4)) << '\n';
    int b[] {1, 3, 5, 1};
    std::cout << (!isSorted(b, 4)) << '\n';
    std::cout << (!isSorted2(b, 0, 4)) << '\n';
}
