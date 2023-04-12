#include <algorithm>
#include <iostream>
#include <vector>

auto main() -> int {
    std::cout << "Enter n: ";
    int n {};
    std::cin >> n;

    std::vector<int> a(n);

    int current {};
    int previous { -1 };
    int count {};
    for (int i {}; i < n; ++i) {
        std::cin >> current;
        if ((i == 0) || (current != previous)) {
            a[count] = current;
            ++count;
        }
        previous = current;
    }

    for (int i {}; i < count; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}