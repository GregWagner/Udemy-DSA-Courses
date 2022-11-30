#include <iostream>

int linear_search(int a[], int size, int key)
{
    for (int i {}; i < size; ++i) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[] {2, 5, 7, 1, 3, 4};
    std::cout << linear_search(a, 6, -3) << '\n';
}
