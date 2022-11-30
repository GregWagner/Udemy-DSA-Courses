#include <iostream>
#include <vector>

template <typename T>
T partition(std::vector<T>& a, int start, int end) {
    T pivot = a[end];
    int leftIndex = start - 1;
    for (int rightIndex { start }; rightIndex < end; ++rightIndex) {
        if (a[rightIndex] < pivot) {
            ++leftIndex;
            // move item at i on correct side of pivot
            std::swap(a[leftIndex], a[rightIndex]);
        }
    }
    // put pivot in the correct place
    std::swap(a[leftIndex + 1], a[end]);
    return leftIndex + 1;
}

template <typename T>
void quickSort(std::vector<T>& a, int start, int end) {
    if (start >= end) {
        return;
    }

    T pivot = partition(a, start, end);
    quickSort(a, start, pivot - 1);
    quickSort(a, pivot + 1, end);
}

int main() {
    std::vector<int> a { 10, 5, 2, 0, 7, 6, 4 };
    quickSort(a, 0, a.size() - 1);

    for (const int x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
