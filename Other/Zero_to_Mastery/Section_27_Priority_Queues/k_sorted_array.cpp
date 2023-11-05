/*
 * k-sorted array is valid if every value you 
 * onlu have to move either k-1 places to the left
 * or k+1 places to the right.
 * Given a valid k-sorted array, to actually sort
 * the array:
 * 1) Brute Force - use the std::sort function O(n log n)
 * 2) Use Max priority queue with k elements in the queue
 */
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
void kSortedArray(std::vector<T> &a, size_t k) {
    std::priority_queue<T> pq;

    for (size_t i {}; i < k; ++i) {
        pq.push(a[i]);
    }

    int start {};
    for (size_t i {k}; i < a.size(); ++i) {
        a[start] = pq.top();
        pq.pop();
        ++start;
        pq.push(a[i]);
    }

    while (!pq.empty()) {
        a[start] = pq.top();
        pq.pop();
        ++start;
    }
}

int main() {
    std::vector<int> a {10, 12, 6, 7, 9};
    kSortedArray<int>(a, 3);
    for (const auto& ele : a) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
