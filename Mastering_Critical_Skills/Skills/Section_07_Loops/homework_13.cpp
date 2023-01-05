#include <iostream>

int main() {
    int test_cases {};
    std::cout << "Enter the number of cases: ";
    std::cin >> test_cases;

    while (test_cases--) {
        int n {};
        std::cout << "Enter n: ";
        std::cin >> n;

        std::cout << "Enter " << n << " numbers: ";
        int sum {};
        int i { 1 };
        while (n--) {
            int num {};
            std::cin >> num;
            int loop_index {};
            int partial_sum { 1 };
            while (loop_index++ < i) {
                partial_sum *= num;
            }
            sum += partial_sum;
            ++i;
        }
        std::cout << sum << '\n';
    }
}