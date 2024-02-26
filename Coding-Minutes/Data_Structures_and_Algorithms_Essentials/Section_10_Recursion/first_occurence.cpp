/*
 * Find the first occurence of an element in an array
 */
#include <iostream>
#include <vector>

int firstOccurance(int a[], int n, int key) {
    if (n == 0) {
        return -1;
    }

    if (a[0] == key) {
        return 0;
    }

    int sub_index = firstOccurance(a + 1, n - 1, key);
    return sub_index == -1 ? -1 : sub_index + 1;
}

int main() {
    int a[]{ 1, 4, 5, 7, 6, 2 };
    int n = sizeof(a) / sizeof(int);
    int key{ 7 };
    std::cout << firstOccurance(a, n, key) << '\n';
}
