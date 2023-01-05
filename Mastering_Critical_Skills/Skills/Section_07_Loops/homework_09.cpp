#include <climits>
#include <iostream>

int main() {
    int test_cases {};
    std::cout << "Enter number of test cases: ";
    std::cin >> test_cases;

    while (test_cases--) {
        int n {};
        std::cout << "Enter n: ";
        std::cin >> n;
        std::cout << "Enter " << n << " numbers: ";
        int min { INT_MAX };
        while (n--) {
            int input {};
            std::cin >> input;
            min = std::min(min, input);
        }
        std::cout << min << '\n';
    }
}