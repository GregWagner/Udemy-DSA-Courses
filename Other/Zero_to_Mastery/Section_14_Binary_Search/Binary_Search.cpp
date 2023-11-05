#include <iostream>

int binary_search(int a[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (a[middle] == key) {
            return middle;
        }
        if (a[middle] > key) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}

int main()
{
    int a[] {1, 3, 5, 7, 9};
    std::cout << binary_search(a, 5, 9) << '\n';
}
