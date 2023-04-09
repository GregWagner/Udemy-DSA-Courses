#include <iostream>

template <typename T>
class Queue {
    public:
        ~Queue() {
            while (head != nullptr) {
                Node* temp = head;
                std::cout << "Deleting " << temp->data << '\n';
                head = head->next;
                delete temp;
                --size;
            }
        }

        void push(T data) {
            Node* temp = new Node();
            temp->data = data;
            if (isEmpty()) {
                head = temp;
            } else {
                tail->next = temp;
            }
            tail = temp;
            ++size;
        }

        T front() {
            if (isEmpty()) {
                std::cerr << "Queue empty\n";
                return -1;
            }
            return head->data;
        }

        T pop() {
            if (isEmpty()) {
                std::cerr << "Queue empty\n";
                return -1;
            }
            Node* temp = head;
            T data = temp->data;
            head = head->next;
            std::cout << "Deleting " << data << '\n';
            delete temp;
            --size;
            return data;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

    private:
        struct Node {
            T data;
            Node* next;
        };

        int size {};

        Node* head {};
        Node* tail {};
};

int main() {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    q.push(50);
    std::cout << "Done\n";
}
