/*
 * Find the character that appears at the highest occcurence.
 * 1) Brute force - O(n^2)
 * 2) Sort then check - O(n log n)
 * 3) Hack - O(n)
 *      Create an array with size of 256 (frequency array)
 *      This works because there is a fixed number of characters
 *
 * Find the word that appears at the highest occurrencce.
 * Neeed hashmap
 */
#include <iostream>
#include <vector>

int highest_char(const std::string& s) {
    std::vector<int> a (256, 0);
    for (const auto& c : s) {
        ++a[c];
    }
    int max {};
    for (const auto& count : a) {
        max = std::max(max, count);
    }
    return max;
}

int main() {
    std::cout << highest_char("greg") << '\n';
}

