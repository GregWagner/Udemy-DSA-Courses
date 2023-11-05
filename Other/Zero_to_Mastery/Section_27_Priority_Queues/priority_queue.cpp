#include <iostream>
#include <vector>

template <typename T>
class PriorityQueue {
    public:
        PriorityQueue() {
        }

        bool isEmpty() {
            return pq.empty();
        }

        int getSize() {
            return pq.size();
        }

        T getMin() {
            if (pq.isEmpty) {
                return 0;
            }
            return pq[0];
        }

        int removeMin() {
            if (pq.empty()) {
                return -1;
            }
            int minElement {pq[0]};
            std::swap(pq[0], pq[pq.size() - 1]);
            pq.pop_back();

            // satisfy the heap property
            size_t parentIndex {};
            while (true) {
                size_t leftChildIndex {2 * parentIndex + 1};
                size_t rightChildIndex {2 * parentIndex + 2};
                size_t minIndex {parentIndex};
                if (leftChildIndex < pq.size() && pq[leftChildIndex] < pq[minIndex]) {
                    minIndex = leftChildIndex;
                } 
                if (rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
                    minIndex = rightChildIndex;
                }
                if (minIndex == parentIndex) {
                    break;
                }
                std::swap(pq[parentIndex], pq[minIndex]);
                parentIndex = minIndex;
            }
            return minElement;
        }

        void insert(T item) {
            std::cout << "Adding " << item << ", Size: " << getSize() << '\n';
            pq.push_back(item);
            std::cout << "Adding " << item << ", Size: " << getSize() << '\n';
            size_t childIndex {pq.size() -1};

            // satisfy the heap property
            size_t parentIndex = childIndex / 2;
            while (childIndex > 0 && pq[parentIndex] > pq[childIndex]) {
                std::swap(pq[parentIndex], pq[childIndex]);
                childIndex = parentIndex;
                parentIndex = childIndex / 2;
            }
        }

        void print() {
            for (const auto& ele : pq) {
                std::cout << ele << ' ';
            }
            std::cout << '\n';
        }

    private:
        std::vector<T> pq;

};

void inplaceHeapSort(std::vector<int> &pq) {
    // Build the heap in the input vector
    for (size_t i {1}; i < pq.size(); ++i) {
        size_t childIndex {i};
        while (childIndex > 0) {
            size_t parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex]) {
                std::swap(pq[parentIndex], pq[childIndex]);
                childIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    // call remove n times
    int size = pq.size();
    while (size >= 1) {
        std::swap(pq[0], pq[size - 1]);
        --size;         // element is removed

        // Down Heapify
        size_t parentIndex {};
        while (true) {
            size_t leftChildIndex {2 * parentIndex + 1};
            size_t rightChildIndex {2 * parentIndex + 2};
            size_t minIndex {parentIndex};
            if (leftChildIndex < size && pq[leftChildIndex] < pq[minIndex]) {
                minIndex = leftChildIndex;
            } 
            if (rightChildIndex < size && pq[rightChildIndex] < pq[minIndex]) {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }
            std::swap(pq[parentIndex], pq[minIndex]);
            parentIndex = minIndex;
        }
    }
}

int main() {
    PriorityQueue<int> p;
    p.insert(10);
    p.insert(20);
    p.insert(30);
    p.insert(40);
    p.insert(50);
    p.insert(60);
    p.insert(70);
    p.print();
    p.insert(0);
    p.print();
    p.insert(5);
    p.print();

    // heap sort - first build min heap that remove all the elements
    while (!p.isEmpty()) {
        std::cout << p.removeMin() << ' ';
    }
    std::cout << '\n';

    std::vector<int> v {5, 1, 2, 0, 8};
    inplaceHeapSort(v);
    for (const auto& e : v) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

