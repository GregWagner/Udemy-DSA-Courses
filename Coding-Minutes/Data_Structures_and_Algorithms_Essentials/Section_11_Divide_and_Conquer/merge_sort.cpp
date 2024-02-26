#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& a, int startingIndex, int endingIndex) {
    int left{ startingIndex };
    int middle{ (startingIndex + endingIndex) / 2 };
    int right{ middle + 1 };

    std::vector<T> temp;

    while (left <= middle && right <= endingIndex) {
        if (a[left] < a[right]) {
            temp.push_back(a[left++]);
        } else {
            temp.push_back(a[right++]);
        }
    }

    // copy the remaning elements
    while (left <= middle) {
        temp.push_back(a[left++]);
    }
    while (right <= endingIndex) {
        temp.push_back(a[right++]);
    }

    // copy back to orginal array
    for (int k{}, i{ startingIndex }; i <= endingIndex; ++i, ++k) {
        a[i] = temp[k];
    }
}

template <typename T>
void mergeSort(std::vector<T>& a, int startingIndex, int endingIndex) {
    if (startingIndex >= endingIndex) {
        return;
    }

    int middleIndex = (startingIndex + endingIndex) / 2;
    mergeSort(a, startingIndex, middleIndex);
    mergeSort(a, middleIndex + 1, endingIndex);

    merge(a, startingIndex, endingIndex);
}

int main() {
    std::vector<int> a{ 10, 5, 2, 0, 7, 6, 4 };
    mergeSort(a, 0, a.size() - 1);
    for (auto const& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
