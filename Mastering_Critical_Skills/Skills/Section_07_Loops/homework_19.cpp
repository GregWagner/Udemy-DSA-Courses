#include <iostream>

int sum_of_digits(int n) {
    int sum {};
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n {}, a {}, b {};
    std::cout << "Enter n, a, and b: ";
    std::cin >> n >> a >> b;

    int sum {};
    for (int i { 1 }; i <= n; ++i) {
        int sod { sum_of_digits(i) };
        if (a <= sod && sod <= b) {
            sum += i;
        }
    }
    std::cout << sum << '\n';
}