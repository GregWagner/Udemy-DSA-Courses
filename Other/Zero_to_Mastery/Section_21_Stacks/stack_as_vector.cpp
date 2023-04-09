#include <iostream>
#include <vector>

template<typename T>
class Stack {
    public:
        void push(T item) {
            a.push_back(item);
        }

        T size() const {
            return a.size();
        }

        void pop() {
            if (isEmpty()) {
                std::cout << "Stack Empty\n";
                return;
            }
            a.pop_back();
        }

        T top() {
            if (isEmpty()) {
                std::cout << "Stack Empty\n";
                return -1;
            }
            return a.back();
        }

        bool isEmpty() const {
            return a.empty();
        }

    private:
       std::vector<T> a;
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

    Stack<double> stack1;
}
