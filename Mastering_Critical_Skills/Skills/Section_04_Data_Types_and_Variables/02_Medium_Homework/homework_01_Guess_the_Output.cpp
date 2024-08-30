#include <iostream>

auto main() -> int {
    int num1{};
    int num2{1};
    int num3{num1 + num2};

    std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, std::cout << num3 << "\n";

    // https://en.wikipedia.org/wiki/Fibonacci_number
}

/*
num1    num2    num3
0       1       1
1       1       2
1       2       3
2       3       5
3       5       8
5       8       13
8       13      21
13      21      34
21      34      55
*/
