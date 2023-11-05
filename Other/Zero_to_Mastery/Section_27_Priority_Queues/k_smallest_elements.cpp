/*
 * Find the k smallest elements in an array
 * in O(n log k) which is better than sorting
 * since sorting woulld be O(n log n) and k < n.
 *
 * Create a maximum priority queue and push k 
 * elements. Then check the rest of the elements
 * in the array and if the element is less than
 * the max element, swap the new element.
 */
#include <iostream>
#include <queue>
#include <vector>

void kSmallestElement(std::vector<int> a, size_t k) {
    std::priority_queue<int> pq;
    for (size_t i {}; i < k; ++i) {
        pq.push(a[i]); 
    }

    for (size_t i {k}; i < a.size(); ++i) {
        if (a[i] < pq.top()) {
            pq.pop();
            pq.push(a[i]);
        }
    }

    while (!pq.empty()) {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v {5, 6, 9, 12, 3, 13, 2};
    kSmallestElement(v, 3);

}
