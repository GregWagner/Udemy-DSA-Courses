#include <iostream>

auto main() -> int {
    int n {};
    std::cout << "Enter an odd number: ";
    std::cin >> n;

    int starting_spaces {};
    int middle_spaces { n - 2 };

    // top half
    for (int i {}; i < n / 2; ++i) {
        for (int spaces {}; spaces < starting_spaces; ++spaces) {
            std::cout << ' ';
        }
        ++starting_spaces;
        std::cout << '*';
        for (int spaces {}; spaces < middle_spaces; ++spaces) {
            std::cout << ' ';
        }
        middle_spaces -= 2;
        std::cout << "*\n";
    }

    // middle
    for (int spaces {}; spaces < starting_spaces; ++spaces) {
        std::cout << ' ';
    }
    std::cout << "*\n";

    // bottom half
    --starting_spaces;
    middle_spaces += 2;
    for (int i {}; i < n / 2; ++i) {
        for (int spaces {}; spaces < starting_spaces; ++spaces) {
            std::cout << ' ';
        }
        --starting_spaces;
        std::cout << '*';
        for (int spaces {}; spaces < middle_spaces; ++spaces) {
            std::cout << ' ';
        }
        middle_spaces += 2;
        std::cout << "*\n";
    }
}