#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// Reverse in place
void problem_1() {
    size_t n {};
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> a(n);
    for (size_t i {}; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    size_t start {};
    size_t end { a.size() - 1 };
    while (start < end) {
        std::cout << "Swapping\n";
        std::swap(a[start], a[end]);
        ++start;
        --end;
    }

    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

// find most frequent number
void problem_2() {
    int n {};
    std::cout << "Enter how many numbers: ";
    std::cin >> n;
    while (n < 0 || n > 150) {
        std::cout << "Value must be positive and less than 151\n";
        std::cin >> n;
    }

    std::vector<int> frequency(151, 0);
    for (int i {}; i < n; ++i) {
        int value {};
        std::cin >> value;
        ++frequency[value];
    }
    int maxCount { frequency[0] };
    int maxValue {};
    for (size_t i { 1 }; i < frequency.size(); ++i) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            maxValue = i;
        }
    }
    std::cout << "The number " << maxValue
              << " occurred " << maxCount << " times.\n";
}

int main() {
    problem_2();
}