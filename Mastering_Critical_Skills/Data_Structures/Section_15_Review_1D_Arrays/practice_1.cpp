#include <iostream>
#include <vector>

void problem_1() {
    size_t n {};
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> a(2, -1);
    for (size_t i {}; i < n; ++i) {
        int value {};
        std::cin >> value;
        if (a[0] < value) {
            a[1] = a[0];
            a[0] = value;
        } else {
            a[1] = std::max(a[1], value);
        }
    }
    std::cout << a[0] << ' ' << a[1] << '\n';
}

void problem_2() {
    size_t n {};
    std::cout << "Enter the size of the array: ";
    while (n < 2) {
        std::cout << "Size must be at least 2\n";
        std::cin >> n;
    }

    std::vector<int> a(n);
    for (size_t i {}; i < a.size(); ++i) {
        std::cin >> a[i];
    }

    std::vector<int> maxValues(2);
    maxValues[0] = std::max(a[0], a[1]);
    maxValues[1] = std::min(a[0], a[1]);

    for (size_t i { 2 }; i < a.size(); ++i) {
        if (a[i] > maxValues[0]) {
            maxValues[1] = maxValues[0];
            maxValues[0] = a[i];
        } else {
            maxValues[1] = std::max(a[i], maxValues[1]);
        }
    }
    std::cout << "The max sum is " << maxValues[0] + maxValues[1] << '\n';
}

int main() {
    // problem_1();
    problem_2();
}