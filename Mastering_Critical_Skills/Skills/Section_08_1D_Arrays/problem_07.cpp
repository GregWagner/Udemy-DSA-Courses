/*
 * Search for a number
 * Find the last occurrence in the array and print its index
 * Note: This could have also been done by shifting each value by 270
 */
#include <iostream>
#include <vector>

int search_for_01(const std::vector<int> &a, int number) {
    for (size_t i {a.size() - 1}; i > 0; --i) {
       if (a[i] == number) {
           return i;
       }
    }
    return -1;
}

// using frequency array
int search_for(const std::vector<int> &a, int number) {
    std::vector<int> freq(501, -1);

    for (size_t i {}; i < a.size(); ++i) {
       freq[a[i]] = i;
    }
    return freq[number];
}

int main() {
    std::cout << std::boolalpha;
    std::vector<int> a {1, 2, 7, 3, 7};
    std::cout << (search_for(a, 7) == 4) << '\n';
    std::cout << (search_for(a, 9) == -1) << '\n';
    std::cout << (search_for(a, 2) == 1) << '\n';
}