#include <iostream>
#include <vector>

template <typename T>
class Stack {
    public:
        Stack() : nextIndex {}, capacity {4} {
            arr = new int[4];
        }

        Stack(int capacity) : nextIndex {}, capacity {capacity} {
            arr = new int[4];
        }

        ~Stack() {
            delete [] arr;
            arr = nullptr;
        }

        void push(T item) {
            if (nextIndex == capacity) {
                std::cout << "Stach Full\n";
                return;
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

        T top() const {
            if (isEmpty()) {
                std::cout << "Stack Empty\n";
                return -1;
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
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    while (!stack.isEmpty()) {
        std::cout << "Size: " << stack.size()
            << ' ' << stack.top() << '\n';
        stack.pop();
    }
}
