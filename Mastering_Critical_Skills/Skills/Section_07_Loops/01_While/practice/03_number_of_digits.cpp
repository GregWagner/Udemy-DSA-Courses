#include <iostream>

auto main() -> int {
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;

    int count {};
    if (num == 0) {
        count = 1;
    } else {
        if (num < 0) {
            num = -num;
        }
        while (num > 0) {
            num /= 10;
            ++count;
        }
    }
    std::cout << "There are " << count << " digits.\n";
}