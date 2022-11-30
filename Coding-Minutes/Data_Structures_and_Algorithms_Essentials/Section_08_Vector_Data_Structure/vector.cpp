#include <iostream>

template <typename T>
class Vector {
    int current_size {};
    int max_size { 1 };
    T* arr {};

public:
    Vector(int max_size_ = 1)
        : max_size { max_size_ }
        , arr { new T[max_size] } {
    }

    void push_back(T data) {
        if (current_size == max_size) {
            // create a new array and delete the old one
            T* old_array = arr;
            max_size *= 2;
            arr = new int[max_size];
            for (int i {}; i < current_size; ++i) {
                arr[i] = old_array[i];
            }
            delete[] old_array;
        }
        arr[current_size] = data;
        ++current_size;
    }

    void pop_back() {
        if (!isEmpty()) {
            --current_size;
        }
    }

    T front() const {
        return arr[0];
    }

    T back() const {
        return arr[current_size - 1];
    }

    T at(int index) const {
        return arr[index];
    }

    int size() const {
        return current_size;
    }

    int capacity() const {
        return max_size;
    }

    bool isEmpty() const {
        return current_size == 0;
    }

    T operator[](int index) {
        return arr[index];
    }
};

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(15);
    v.push_back(6);

    v.pop_back();

    std::cout << v.front() << '\n';
    std::cout << v.back() << '\n';
    std::cout << v.at(2) << '\n';

    std::cout << v.size() << '\n';
    std::cout << v.capacity() << '\n';
}