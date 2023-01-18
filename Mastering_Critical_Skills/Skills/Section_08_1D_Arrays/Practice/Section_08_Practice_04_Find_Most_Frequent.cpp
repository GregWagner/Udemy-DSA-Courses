#include <iostream>
#include <vector>

auto main() -> int {
    int n {};
    std::cout << "Enter how many numbers: ";
    std::cin >> n;
    while (n < 0 || n > 200) {
        std::cout << "Value must be positive and less than 201\n";
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
