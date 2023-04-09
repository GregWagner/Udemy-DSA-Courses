#include <iostream>

template <typename T>
class Stack {
    public:
        Stack() : head {}, length {} {};

        Stack(T data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = head;
            head = temp;
            ++length;
        }

        size_t size() const {
            return length;
        }

        bool empty() const {
            return length == 0;
        }

        void push(T data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = head;
            head = temp;
            ++length;
        }

        void pop() {
            if (length == 0) {
                std::cerr << "Stack Underflow\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            --length;
        }

        T top() const {
            if (length == 0) {
                std::cerr << "Stack Underflow\n";
                return -1;
            }
            return head->data;
        }

    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* head;
        size_t length;
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << "Size: " << s.size() << '\n';
    while (!s.empty()) {
        std::cout << s.top() << '\n';
        s.pop();
    }
    std::cout << "Size: " << s.size() << '\n';
}
