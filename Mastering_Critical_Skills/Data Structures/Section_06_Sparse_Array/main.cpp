#include "ArrayLinkedList.h"
#include <iostream>

int main() {
    ArrayLinkedList array(10);
    array.setValue(50, 5);
    array.setValue(20, 2);
    array.setValue(70, 7);
    array.setValue(40, 4);
    array.printArray();
    array.printArrayNonzero();

    std::cout << array.getValue(7) << '\n';

    ArrayLinkedList array2(10);
    array2.setValue(1, 4);
    array2.setValue(3, 7);
    array2.setValue(4, 6);
    array.add(array2);
    array.printArray();
}