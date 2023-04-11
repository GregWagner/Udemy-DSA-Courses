#include <iostream>

auto main() -> int {
    std::cout << "Enter the number of test cases: ";
    int t {};
    std::cin >> t;

    while (t--) {
        std::cout << "Enter n: ";
        int n {};
        std::cin >> n;

        bool firstNumber { true };
        int min {};

        std::cout << "Enter n numbers: ";
        int num {};
        while (n--) {
            std::cin >> num;
            if (firstNumber) {
                min = num;
                firstNumber = false;
            } else {
                min = std::min(min, num);
            }
        }
        std::cout << min << '\n';
    }
}