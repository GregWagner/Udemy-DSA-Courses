#include <iostream>
#include <vector>

template <typename T>
class Stack {
    public:
        Stack() : nextIndex {}, capacity {4} {
            arr = new int[4];
        }

        ~Stack() {
            delete [] arr;
            arr = nullptr;
        }

        void push(T item) {
            if (nextIndex == capacity) {
                // double the array
                T *newArray = new int[capacity * 2];
                for (int i {}; i < capacity; ++i) {
                    newArray[i] = arr[i];
                }
                capacity *= 2;
                delete [] arr;
                arr = newArray;
            }
            arr[nextIndex] = item;
            ++nextIndex;
        }

        int size() const {
            return nextIndex;
        }

        void pop() {
            if (isEmpty()) {
                std::cout << "Stack Empty\n";
                return;
            }
            --nextIndex;
        }

        T top() {
            if (isEmpty()) {
                std::cout << "Stack Empty\n";
                return 0;
            }
            return arr[nextIndex - 1];
        }

        bool isEmpty() const {
            return nextIndex == 0;
        }

    private:
       int nextIndex {};
       int capacity {};
       T *arr;
};

int main() {
    Stack<int> stack;
    for (int i {}; i < 10; ++i) {
        stack.push(i);
    }

    while (!stack.isEmpty()) {
        std::cout << "Size: " << stack.size()
            << ' ' << stack.top() << '\n';
        stack.pop();
    }
}
