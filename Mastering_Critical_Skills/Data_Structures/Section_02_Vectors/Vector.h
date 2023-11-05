#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iostream>

class Vector {
private:
    int* arr {};
    int size {}; // user size
    int capacity {}; // actual size

public:
    Vector(int size)
        : size { size < 0 ? 1 : size }
        , capacity { size + 10 } {
        arr = new int[capacity] {};
    }

    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }

    int get(int index) {
        assert(0 <= index && index < size);
        return arr[index];
    }

    void set(int index, int value) {
        assert(0 <= index && index < size);
        arr[index] = value;
    }

    void print() {
        for (int i {}; i < size; ++i) {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }

    int find(int value) {
        for (int i {}; i < size; ++i) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int getFront() {
        return arr[0];
    }

    int getBack() {
        return arr[size - 1];
    }

    void push_back(int value) {
        if (size == capacity) {
            expandCapacity();
        }
        arr[size] = value;
        ++size;
    }

    void insert(int index, int value) {
        assert(0 <= index && index < size);

        // make sure we have room currently to add an item
        if (size == capacity) {
            expandCapacity();
        }

        // shift all data to the right first starting from the end
        for (int p = size - 1; p >= index; --p) {
            arr[p + 1] = arr[p];
        }

        arr[index] = value;
        ++size;
    }

    // note: no need to change the size or capacity
    void right_rotate() {
        // save the last element
        int temp { arr[size - 1] };

        // shift all data to the right first starting from the end
        for (int p = size - 2; p >= 0; --p) {
            arr[p + 1] = arr[p];
        }
        arr[0] = temp;
    }

    // note: no need to change the size or capacity
    void left_rotate() {
        int temp { arr[0] };
        for (int p { 1 }; p < size; ++p) {
            arr[p - 1] = arr[p];
        }
        arr[size - 1] = temp;
    }

    void right_rotate(int steps) {
        steps %= size;
        while (steps--) {
            right_rotate();
        }
    }

    int pop(int index) {
        assert(0 <= index && index < size);
        int temp = arr[index];
        for (int p { index }; p < size; ++p) {
            arr[p] = arr[p + 1];
        }
        --size;
        return temp;
    }

    // improved search - assuming that we call find for only a
    // small number of values.
    // each time you find a value, shift it one step to left so
    // eventually, the values that are queried a lot will move to
    // the front
    int find_transposition(int value) {
        auto result = find(value);
        if (result > 0) {
            // item was found and not in the first position
            std::swap(arr[result], arr[result - 1]);
            --result;
        }
        return result;
    }

private:
    void expandCapacity() {
        capacity *= 2;
        int* newArr = new int[capacity] {};
        for (int i {}; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};

#endif
