#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter the number of integers to read: ";
    std::cin >> n;

    int odd_sum {}, odd_count {};
    int even_sum {}, even_count {};
    while (n--) {
        int input {};
        std::cin >> input;
        if (n % 2 == 0) {
            ++even_count;
            even_sum += input;
        } else {
            ++odd_count;
            odd_sum += input;
        }
    }
    std::cout << (odd_sum / odd_count) << ' '
              << (even_sum / even_count) << '\n';
}