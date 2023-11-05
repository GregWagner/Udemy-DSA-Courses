#include "Vector.h"
#include <iostream>

int main() {
    Vector v(10);

    for (int i {}; i < 10; ++i) {
        v.set(i, i);
    }
    v.print();
    std::cout << v.find(5) << ' ' << v.find(55) << '\n';

    v.push_back(99);
    v.print();

    v.insert(0, 55);
    v.print();

    v.right_rotate();
    v.print();

    v.left_rotate();
    v.print();

    std::cout << "Poping 2nd item: " << v.pop(2) << '\n';
    v.print();
}
