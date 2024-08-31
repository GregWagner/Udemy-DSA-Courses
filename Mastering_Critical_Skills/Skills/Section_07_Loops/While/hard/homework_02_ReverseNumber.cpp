#include <cmath>
#include <iostream>

auto main() -> int {
    std::cout << "Enter number: ";
    int n {};
    std::cin >> n;

    int answer_1 {};
    int answer_2 {};
    while (n) {
        answer_1 *= 10;
        answer_1 += n % 10;

        answer_2 *= 10;
        answer_2 += n % 10 * 3;

        n /= 10;
    }
    std::cout << answer_1 << ' ' << answer_2 << '\n';
}