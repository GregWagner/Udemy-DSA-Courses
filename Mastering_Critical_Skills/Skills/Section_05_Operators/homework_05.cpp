#include <iostream>

int main() {
    int nb {}, ng {}, nt {};
    std::cin >> nb >> ng >> nt;

    std::cout << std::boolalpha;
    std::cout << (nb > 25) << '\n';
    std::cout << (ng <= 30) << '\n';
    std::cout << ((nb > 20 && nt > 2) || (ng > 30 && nt > 4)) << '\n';
    std::cout << (nb < 60 || ng < 70) << '\n';
    std::cout << (nb < 60 || ng < 70) << '\n';
    std::cout << (nb - 10 == ng) << '\n';
    std::cout << (nb - ng > 10 || nt > 5) << '\n';
    std::cout << (nb - 10 == ng || ng - 15 == nb) << '\n';
}