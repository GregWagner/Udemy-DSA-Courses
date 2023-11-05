/*
 * e^x using taylor series
 * Required 3 operations sum(), factorial(), and power()
 * 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + n terms
 * Need to use static variables since a function can only return 1 value
 *
 * NOTE: Using static variables causes a problem if the function is called
 * more than one time.
 */
#include <iostream>

double e(int x, int n) {
    static double power {1.0};      // numerator
    static double factorial {1.0};  // demoninator

    if (n == 0) {
        return 1.0;
    }

    double result = e(x, n - 1);

    // update (upon return of recursive function) global
    // or static numerator and demoninator
    power *= x;
    factorial *= n;
    return result + (power / factorial);
}

double e_loop(int x, int n) {
    double s {1.0};
    double numerator {1.0};
    double demoninator {1.0};

    for (int i {1}; i < n; ++i) {
        numerator *= x;
        demoninator *= i;
        s += numerator /  demoninator;
    }
    return s;
}

// Using Horner's rule (iterative)
// This reduces the number of multiplations from 0(n^2) to O(n)
double fast_e_loop(int x, int n) {
    double s {1.0};
    while (n > 0) {
        s = 1.0 + (x * s) / n;
        --n;
    }
    return s;
}

// Using Horner's rule (recursion)
// This reduces the number of multiplations from 0(n^2) to O(n)
double fast_e(int x, int n) {
   static double s {1.0};
    if (n == 0) {
        return s;
    }
    s = 1.0 + (x * s) / n;
    return fast_e(x, n - 1);
}

int main() {
    std::cout << e(3, 10) << '\n';
    std::cout << e_loop(3, 10) << '\n';
    std::cout << fast_e_loop(3, 10) << '\n';
    std::cout << fast_e(3, 10) << '\n';

//  std::cout << e(1, 10) << '\n';
    std::cout << e_loop(1, 10) << '\n';
    std::cout << fast_e_loop(1, 10) << '\n';
    std::cout << fast_e(1, 10) << '\n';
}
