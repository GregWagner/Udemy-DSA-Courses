#include <iostream>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    int count { 1 };
    int oddSum {};
    int oddCount {};
    int evenSum {};
    int evenCount {};
    while (n--) {
        std::cout << "Enter number " << count << ": ";
        int number {};
        std::cin >> number;
        if (count % 2 == 0) {
            evenSum += number;
            ++evenCount;
        } else {
            oddSum += number;
            ++oddCount;
        }
        ++count;
    }
    std::cout << oddSum / oddCount << ' '
              << evenSum / evenCount << '\n';
}