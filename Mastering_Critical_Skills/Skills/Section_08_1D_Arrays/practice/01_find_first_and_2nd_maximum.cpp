#include <iostream>
#include <vector>

auto main() -> int {
    int n{};
    std::vector<int> a(200);

    std::cout << "Enter n: ";
    int n;
    std::cin >> n;

    for (int i{}; i < n; ++i) {
        std::cin >> a[i];
    }

    int first_max{};
    int second_max{};
    for (int i{}; i < n; ++i) {
        if (a[i] > first_max) {
            second_max = first_max;
            first_max = a[i];
        } else if (a[i] > second_max) {
            second_max = a[i];
        }
    }
    std::cout << first_max << ' ' << second_max << '\n';
}
