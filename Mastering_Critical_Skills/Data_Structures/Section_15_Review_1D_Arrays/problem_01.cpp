/*
 * Prinnt Yes if the array is increasing
 */
#include <iostream>
#include <vector>

bool is_increasing_array(std::vector<int>& a) {

    for (size_t i { 1 }; i < a.size(); ++i) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> a { 1, 2, 2, 5 };
    std::vector<int> b { 1, 0, 7, 8, 9 };
    std::vector<int> c { -10, 10 };

    std::cout << std::boolalpha;
    std::cout << (is_increasing_array(a) == true) << '\n';
    std::cout << (is_increasing_array(b) == false) << '\n';
    std::cout << (is_increasing_array(c) == true) << '\n';
}