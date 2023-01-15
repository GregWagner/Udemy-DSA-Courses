/*
 * Print Me
 * if b is -1, print 2 * a + 1
 * if b is 1, print a * a
 * Hint - you need to find a simple 1 line formula
 * Need to convert b to 0 or 1
 */
#include <iostream>

auto main() -> int
{
    int a{};
    std::cout << "Enter a number: ";
    std::cin >> a;

    int b{};
    std::cout << "Enter either -1 or 1: ";
    std::cin >> b;

    // precalculate both equations
    int if_b_is_minus_one{2 * a + 1};
    int if_b_is_one{a * a};

    // b = 1: b_is_1 = 1
    // b = -1: b_is_1 = 0
    int b_is_1 = (b + 1) / 2;
    // b = 1: b_is_neg_1 = 0
    // b = -1: b_is_neg_1 = 1
    int b_is_neg_1{1 - b_is_1};

    // Either 1 * equation_1 + 0 * equation_2
    // or
    //        0 * equation_1 + 1 * equation_2
    std::cout << b_is_1 * if_b_is_one + b_is_neg_1 * if_b_is_minus_one << '\n';
}