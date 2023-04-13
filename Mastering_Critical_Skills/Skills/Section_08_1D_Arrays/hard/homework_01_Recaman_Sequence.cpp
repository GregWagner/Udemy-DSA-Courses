#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<bool> a(1000, false);

    int lastIndex {};
    int lastValue {};
    a[0] = true;

    for (int i {}; i < n; ++i) {
        int value { lastValue - lastIndex - 1 };
        if (value > 0 && a[value] == false) {
            lastValue = value;
        } else {
            lastValue = lastValue + lastIndex + 1;
        }
        a[lastValue] = true;
        ++lastIndex;
    }
    std::cout << lastValue << '\n';
}