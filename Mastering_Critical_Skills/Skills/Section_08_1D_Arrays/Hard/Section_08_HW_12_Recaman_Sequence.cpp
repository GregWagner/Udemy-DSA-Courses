/*
 * Recaman's Sequence
 */
#include <iostream>
#include <vector>
#include <unordered_map>

void recmans_sequence(std::vector<int> &a) {
    std::unordered_map<int, int> m;
    m[0] = 1;
    a[1] = 1; m[1] = 1;

    for (size_t i {2}; i < a.size(); ++i) {
        int value = a[i - 1] - (i - 1) - 1;
        if (value <= 0 || m.count(value)) {
            value = a[i - 1] + (i - 1) + 1;
        }
        a[i] = value;
        m[value] = 1;
    }
}


auto main() -> int {
    std::vector<int> a(200, 0);
    recmans_sequence(a);

    std::cout << std::boolalpha;
    std::cout << (a[6] == 13) << '\n';
    std::cout << (a[9] == 21) << '\n';
    std::cout << (a[17] == 25) << '\n';
}