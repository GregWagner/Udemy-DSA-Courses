#include <iostream>

void sort(int a[], int size)
{
    for (int i {}; i < size; ++i) {
        int smallestIndex {i};
        for (int j {i + 1}; j <= size; ++j) {
            if (a[smallestIndex] > a[j]) {
                smallestIndex = j;
            }
        }
        std::swap(a[i], a[smallestIndex]);
    }
}

int main()
{
    int a[] {7, 5, 3, 6, 8};
    sort(a, 5);
    for (auto e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}
