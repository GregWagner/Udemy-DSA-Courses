#include <iostream>
#include <cmath>

class Array {
    public:
        Array() {}

        Array(int a[], int size) {
            this->length = size;
            for (int i {}; i < size; ++i) {
                this->a[i] = a[i];
            }
        }

        void display() const {
            std::cout << "Elements are\n";
            for (int i {}; i < length; ++i) {
                std::cout << a[i] << ' ';
            }
            std::cout << '\n';
        }

        void append(int value) {
            if (length < size) {
                a[length++] = value;
            }
        }

        void insert(int index, int value) {
            if (index >= 0 && index <= length) {
                for (int i {length}; i > index; --i) {
                    a[i] = a[i - 1];
                }
                a[index] = value;
                ++length;
            }
        }

        int remove(int index) {
            int temp {-1};
            if (index >= 0 && index <= length) {
                temp = a[index];
                for (int i {index}; i < length; ++i) {
                    a[i] = a[i + 1];
                }
            }
            --length;
            return temp;
        }

        int linear_search(int key) {
            for (int i {}; i < length; ++i) {
                if (a[i] == key) {
#ifdef TRANSPOSITION
                    // transposition to speed up search if repeated
                    std::swap(a[i], a[i - 1]);
                    return i - 1;
#endif
#ifdef MOVE_TO_HEAD
                    // move o head to speed up search
                    std""Swap(a[0], a[i]);
                    return 0;
#endif

                    return i;
                }
            }
            return -1;
        }

        int binary_search(int key, int low, int high) {
            while (low <= high) {
                int middle = std::floor(low + high) / 2;
                if (a[middle] == key) {
                    return  middle;
                }
                if (a[middle] > key) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            }
            return -1;
        }

    private:
        int *a {};
        int size {};
        int length {};
};

int main() {
    int a[] {2, 3, 4, 5, 6};
    Array arr {a, 5};
    arr.display();

    arr.append(10);
    arr.display();

    arr.insert(2, 99);
    arr.display();

    arr.remove(0);
    arr.display();

    std::cout << arr.binary_search(6, 0, 5) << '\n';
}
