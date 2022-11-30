/*
 * Data must be in a specific range (for example 0-100)
 * Create a frequency count array and then scan from left to right
 */
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> countingSort(const std::vector<T>& a) {
    // find the largest element in the array
    int largest_number {};
    for (const auto& ele : a) {
        largest_number = std::max(largest_number, ele);
    }

    // use the largest element to create a new array
    std::vector<T> frequency(largest_number + 1, 0);
    for (const auto& ele : a) {
        ++frequency[ele];
    }

    // put back the elements frem frequency into the answer
    std::vector<T> answer(a.size());
    size_t index {};
    for (size_t i {}; i < frequency.size(); ++i) {
        while (frequency[i]) {
            answer[index++] = i;
            --frequency[i];
        }
    }
    return answer;
}

template <typename T>
void print(const std::vector<T>& a) {
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a { 6, 2, 7, 4, 8, 1, 3 };
    a = countingSort(a);
    print(a);
}
