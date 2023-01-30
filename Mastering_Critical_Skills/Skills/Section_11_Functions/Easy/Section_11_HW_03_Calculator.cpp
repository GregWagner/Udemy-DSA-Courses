#include <iostream>

auto read_two(double& a, double& b) {
    std::cout << "Enter 2 integers: ";
    std::cin >> a >> b;
}

auto display_menu() -> int {
    int operation {};
    while (operation < 1 || operation > 5) {
        std::cout << "Enter operation: \n"
                  << "1 - Add\n2 - Subtract\n3 - Multiply\n"
                  << "4 - Divide\n5 - End program\n";
        std::cin >> operation;
    }
    return operation;
}

auto add(double& a, double& b) {
    return a + b;
}

auto subtract(double& a, double& b) {
    return a - b;
}

auto multiply(double& a, double& b) {
    return a * b;
}

auto divide(double& a, double& b) {
    return a / b;
}

auto main() -> int {
    int operation_count {};
    bool done {};
    while (!done) {
        double a {}, b {};
        read_two(a, b);

        int operation = display_menu();
        switch (operation) {
        case 1:
            ++operation_count;
            std::cout << a << " + " << b << " = " << add(a, b) << '\n';
            break;
        case 2:
            ++operation_count;
            std::cout << a << " - " << b << " = " << subtract(a, b) << '\n';
            break;
        case 3:
            ++operation_count;
            std::cout << a << " * " << b << " = " << multiply(a, b) << '\n';
            break;
        case 4:
            if (b) {
                ++operation_count;
                std::cout << a << " / " << b << " = " << divide(a, b) << '\n';
            } else {
                std::cout << "Unable to divide by zero\n";
            }
            break;
        case 5:
            done = true;
            break;
        default:
            std::cout << "Invalid operation - try again\n";
        }
    }
    std::cout << "There were " << operation_count << " operations performed\n";
}