#include <iostream>

auto main() -> int {
    std::cout << "Enter the number of boys, the number of girls and the number of teachers: ";
    int nb {};
    int ng {};
    int nt {};
    std::cin >> nb >> ng >> nt;

    std::cout << (nb > 25) << '\n';
    std::cout << (nb <= 30) << '\n';
    std::cout << (nb > 20 && nt > 2 || ng > 30 && nt > 4) << '\n';
    std::cout << (nb < 60 || ng < 70) << '\n';
    std::cout << (nb < 60 && ng < 70) << '\n';
    std::cout << (nb == ng + 10) << '\n';
    std::cout << ((nb - ng > 10) || (nt > 5)) << '\n';
    std::cout << ((nb == ng + 10) || (ng == nb + 15)) << '\n';
}