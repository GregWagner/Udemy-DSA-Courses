#include <iostream>

template <typename T>
class Queue {
    public:
        Queue(int capacity=5) : capacity{capacity}, size{}, nextIndex{}, firstIndex{} {
            arr = new T[capacity];
        }

        ~Queue() {
            delete [] arr;
        }

        bool isEmpty() const {
            return size == 0;
        }

        int getSize() const {
            return size;
        }

        void push(T data) {
            if (size == capacity) {
                T*newArr = new T[2 * capacity];
                int j {};
                for (int i {firstIndex}; i < capacity; ++i) {
                    newArr[j] = arr[i];
                    j++; 
                }
                for (int i {}; i < firstIndex; ++i) {
                    newArr[j] = arr[i];
                    j++; 
                }
                firstIndex = 0;
                nextIndex = capacity;
                capacity *= 2;
                delete [] arr;
                arr = newArr;
                return;
            }
            arr[nextIndex] = data;
            nextIndex = (nextIndex + 1) % capacity;
            ++size;
            std::cout << "PUSH: Index: " << nextIndex << '\n';
        }

        T front() const {
            if (isEmpty()) {
                std::cerr << "Queue is empty\n";
                return - 1;
            }
            return arr[firstIndex];
        }

        T pop() {
            if (isEmpty()) {
                std::cerr << "Queue is empty\n";
                return -1;
            }
            int temp = arr[firstIndex];
            --size;
            firstIndex = (firstIndex + 1) % capacity;
            std::cout << "POP : Front Index: " << firstIndex << '\n';
            return temp;
        }

    private:
        T* arr;
        int capacity {};
        int size {};
        int nextIndex {};
        int firstIndex {};
};

int main() {
    Queue<int> q;

    std::cout << std::boolalpha;
    std::cout << (q.isEmpty() == true) << '\n';
    std::cout << (q.getSize() == 0) << '\n';
    q.push(10);
    std::cout << (q.isEmpty() == false) << '\n';
    std::cout << (q.getSize() == 1) << '\n';
    std::cout << (q.front() == 10) << '\n';
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    std::cout << (q.getSize() == 5) << '\n';
    std::cout << (q.pop() == 10) << '\n';
    std::cout << (q.getSize() == 4) << '\n';
    q.push(15);
    std::cout << (q.getSize() == 5) << '\n';

    std::cout << "Size: " << q.getSize() << '\n';
    std::cout << "Front: " << q.front() << '\n';
}
