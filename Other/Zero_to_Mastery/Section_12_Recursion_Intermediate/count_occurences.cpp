/*
 * Count occcurences of an elemment
 */
#include <iostream>
#include <vector>

int countOccurencces(const std::vector<int> &a, int key, size_t index = 0) {
    if (index > a.size()) {
        return 0;
    }
    if (a[index] == key) {
        return 1 + countOccurencces(a, key, index + 1);
    }
    return countOccurencces(a, key, index + 1);
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {5, 5, 6, 5, 6};
    std::cout << (countOccurencces(a, 5) == 3) << '\n';
    std::cout << (countOccurencces(a, 6) == 2) << '\n';
    std::cout << (countOccurencces(a, 9) == 0) << '\n';

}
