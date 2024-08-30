#include <iostream>

auto main() -> int {
    std::cout << std::boolalpha;
    std::cout << "1  false ";
    std::cout << (true && true && false && true) << '\n';
    // T && T && F && T
    //      T && F && T = false

    std::cout << "2  true ";
    std::cout << ((true && true && false && true) || (true && true)) << '\n';
    // T && T && F && T || T && T
    // T && T && F && T || T && T
    // F || T = true

    std::cout << "3  true ";
    std::cout << ((true && true && true && true) || (true && (true || false))) << '\n';
    // T && T && T && T || T && (T || F)
    // T && T && T && T || T && T
    // T || T = true

    std::cout << "4  true ";
    std::cout << ((true && true && true) || (true && (false || (true && (true && true))))) << '\n';
    // T && T && T || T && (F || (T && (T && T)))
    // T && T && T || T && (F || (T && T))
    // T && T && T || T && (F || T)
    // T && T && T || T && T
    // T && T && T && T = true

    std::cout << "5  true ";
    std::cout << ((true && true) || (true && false && true) || (true && true && false) || (true && (true || false))) << '\n';
    // T && T || T && F && T || T && T && F || (T && (T || F))
    // T && T || T && F && T || T && T && F || (T && T)
    // T && T || T && F && T || T && T && F || T
    // T && T || T && F && T || F || T
    // T && T || F || F || T
    // T || F || F || T = true

    std::cout << "6  true ";
    std::cout << ((true && true) || (true && false && true) || ((true && true && false) || (true && (true || false)))) << '\n';
    // T && T || T && F && T || (T && T && F || (T && (T || F)))
    // T && T || T && F && T || (T && T && F || (T && T))
    // T && T || T && F && T || (T && T && F || T)
    // T && T || T && F && T || (F || T)
    // T && T || T && F && T || T
    // T && T || F || T
    // T || F || T = true

    std::cout << "7  true ";
    std::cout << ((((true && true) || (true && false && true) || true) && true && false) || (true && (true || false))) << '\n';
    // (T && T || T && F && T || T) && T && F || (T && (T || F))
    // (T && T || T && F && T || T) && T && F || (T && T)
    // (T && T || T && F && T || T) && T && F || T
    // (T && T || F || T) && T && F || T
    // (T || F || T) && T && F || T
    // T && T && F || T
    // F || T = true

    std::cout << "8  true ";
    std::cout << ((true && true) || (true && ((false && true) || (true && true)) && false) || (true && (true || false))) << '\n';
    // T && T || T && (F && T || T && T) && F || (T && (T || F))
    // T && T || T && (F && T || T && T) && F || (T && T)
    // T && T || T && (F && T || T && T) && F || T
    // T && T || T && (F && T || T) && F || T
    // T && T || T && (F || T) && F || T
    // T && T || T && T && F || T
    // T && T || F || T
    // T || F || T = true
}