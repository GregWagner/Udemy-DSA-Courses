#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(500 + 270, 0);

    for (int i {}; i < n; ++i) {
        int value {};
        std::cin >> value;
        //shift the value
        ++a[value + 500];
    }

    int mostFrequentIndex {};
    for (int i { 1 }; i < a.size(); ++i) {
        if (a[i] > a[mostFrequentIndex]) {
            mostFrequentIndex = i;
        }
    }
    // unshift the value
    std::cout << mostFrequentIndex - 500 << " repeated "
              << a[mostFrequentIndex] << " times.\n";
}
