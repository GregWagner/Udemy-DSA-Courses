/*
 * Remove duplicates in an array, keeping the order 
 * in the same order.
 *
 * Brute Force - O(n^2)
 * Using hashmap = O(n)
 */
#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
std::vector<T> remove_duplicates(std::vector<T> &v) {
    std::vector<T> results;
    std::unordered_map<T, bool> hash;
    for (auto e : v) {
        if (hash.count(e) == 0) {
            hash[e] = true;
            results.push_back(e);
        }
    }
    return results;
}

int main() {
    std::vector<int> v {1, 2, 3, 2, 1, 5, 4, 1, 3};
    auto results = remove_duplicates(v);
    for (auto ele : results) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';

}
