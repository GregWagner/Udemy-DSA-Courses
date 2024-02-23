/*
 * Quick Sort
 *          1, 9, 2, 8, 5, 6, 4, 7
 *       7  1  2  5  6  4 7       9  8
 *       4  1  2  4  5  6 7       9  8
 *       5  1  2  4 5 6 7       9  8
 *       4  1  2  4 5 6 7       9  8
 *       2  1  2  4 5 6 7       9  8
 *       1  1  2  4 5 6 7       9  8
 */
#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T> &a) {
    for (const auto& e : a) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

template <typename T>
int partition1(std::vector<T> &a, int startingIndex, int endingIndex) {
    int i {startingIndex};
    int pivot {a[endingIndex]};

    for (int j {startingIndex}; j <= endingIndex - 1; ++j) {
        if (a[j] < pivot) {
            std::swap(a[i], a[j]);
            ++i;
        }
    }
    std::swap(a[i], a[endingIndex]);
    return i;
};

template <typename T>
int partition(std::vector<T> &a, int startingIndex, int endingIndex) {
    T pivot {a[endingIndex]};
    std::cout << "Pivot: " << pivot << ' ' << "Starting: " << startingIndex << ' '
        << "Ending: " << endingIndex << '\n';
    printVector(a);

    // find out where the partion goes
    int countSmaller {};
    for (int i {startingIndex}; i < endingIndex; ++i) {
        if (a[i] < pivot) {
            ++countSmaller;
        }
    }

    int pivotIndex = countSmaller + startingIndex;
    std::cout << "Moving pivot: " << a[endingIndex] << " "
        << a[pivotIndex] << '\n';
    std::swap(a[pivotIndex], a[endingIndex]);

    for (int i {startingIndex}; i < pivotIndex; ++i) {
        if (a[i] > a[pivotIndex]) {
            while (a[endingIndex] >= a[pivotIndex]) {
                --endingIndex;
            }
            std::cout << "Swapping " << a[i] << " with " << a[endingIndex] << '\n';
            std::swap(a[i], a[endingIndex]);
            --endingIndex;
        }
    }
    printVector(a);
    std::cout << "-------------------------------------\n";
    return pivotIndex;
}

template <typename T>
void quickSort(std::vector<T> &a, int startingIndex, int endingIndex) {
    // base case
    if (startingIndex >= endingIndex) {
        return;
    }
    int partionIndex {partition1(a, startingIndex, endingIndex)};
    printVector(a);
    std::cout << "-------------------------------------\n";
    quickSort(a, startingIndex, partionIndex - 1);
    quickSort(a, partionIndex + 1, endingIndex);
}

int main() {
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::vector<int> a {1, 9, 2, 8, 5, 6, 4, 7};
    quickSort(a, 0, a.size() - 1);
    printVector(a);
}
