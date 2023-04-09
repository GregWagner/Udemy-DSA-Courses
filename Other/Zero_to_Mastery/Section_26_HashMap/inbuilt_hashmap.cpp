/*
 * map - balanced Binary Search Tree
 *       items are ordered
 *       Insert     O(log n)
 *       Search     O(log n)
 *       Update     O(log n)
 */
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>

int main() {
    std::unordered_map<std::string, int> hashtable;

    // inserting
    std::pair<std::string, int> p {"abc", 1};
    hashtable.insert(p);
    hashtable["def"] = 2;   // array like insertion

    // find/access
    std::cout << hashtable["abc"] << '\n';
    std::cout << hashtable.at("abc") << '\n';

    // check if key present
    if (hashtable.count("abc") > 0) {
        std::cout << "Key is present\n";
    }

    // update
    hashtable["abc"] = 22;

    // delete
    hashtable.erase("abc");
}
