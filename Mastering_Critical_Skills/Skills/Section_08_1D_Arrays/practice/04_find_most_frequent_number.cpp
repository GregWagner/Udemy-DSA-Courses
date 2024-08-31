#include <algorithm>
#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n + 1, 0);
    for (int i {}; i < n; ++i) {
        int num {};
        std::cin >> num;
        ++a[num];
    }
    int maxValue { a[0] };
    int maxIndex { 0 };
    for (int i { 1 }; i < n + 1; ++i) {
        if (a[i] > maxValue) {
            maxValue = a[i];
            maxIndex = i;
        }
    }
    std::cout << maxIndex << " is repeated " << maxValue << " times\n";
}