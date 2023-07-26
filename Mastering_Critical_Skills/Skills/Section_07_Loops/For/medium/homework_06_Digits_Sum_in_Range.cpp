#include <iostream>

auto main() -> int {
    std::cout << "Enter n, a, and b: ";
    int n {}, a {}, b {};
    std::cin >> n >> a >> b;

    int answer {};
    for (int num { a }; num <= n; ++num) {
        int sumOfDigits {};
        int n { num };
        while (n) {
            sumOfDigits += n % 10;
            n /= 10;
        }
        if (sumOfDigits >= a && sumOfDigits <= b) {
            answer += num;
        }
    }
    std::cout << answer << '\n';
}