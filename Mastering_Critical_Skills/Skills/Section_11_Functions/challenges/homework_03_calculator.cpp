#include <iostream>

auto menu() -> int {
    int selection {};
    while (selection < 1 || selection > 5) {
        std::cout << "\nEnter selection:\n"
                  << "1) Add 2 numbers\n"
                  << "2) Subtract 2 numbers\n"
                  << "3) Multiply 2 numbers\n"
                  << "4) Divide 2 numbers\n"
                  << "5) Quit\n";
        std::cin >> selection;
    }
    return selection;
}

auto read2Numbers(double& a, double& b) -> void {
    std::cout << "Enter 2 numbers: ";
    std::cin >> a >> b;
}

auto add(double a, double b) -> double {
    return a + b;
}
auto subtract(double a, double b) -> double {
    return a - b;
}
auto multiply(double a, double b) -> double {
    return a * b;
}
auto divide(double a, double b) -> double {
    if (b == 0) {
        std::cout << "Cannt divide by zero\n";
        return 0;
    }
    return a / b;
}

auto main() -> int {
    int selection {};
    while (selection != 5) {
        double a {}, b {};
        selection = menu();
        switch (selection) {
        case 1:
            read2Numbers(a, b);
            std::cout << add(a, b) << '\n';
            break;
        case 2:
            read2Numbers(a, b);
            std::cout << subtract(a, b) << '\n';
            break;
        case 3:
            read2Numbers(a, b);
            std::cout << multiply(a, b) << '\n';
            break;
        case 4:
            read2Numbers(a, b);
            break;
        }
    }
}