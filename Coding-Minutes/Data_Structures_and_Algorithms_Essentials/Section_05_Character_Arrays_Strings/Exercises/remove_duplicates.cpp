#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

std::string removeDuplicate(std::string s) {
    std::unordered_set<char> hash;
    std::string sorted_results;
    std::vector<char> results;

    for (const auto& c : s) {
        if (hash.find(c) == hash.end()) {
            hash.emplace(c);
            results.push_back(c);
        }
    }
    std::sort(begin(results), end(results));
    for (const auto& c : results) {
        sorted_results += c;
    }
    return sorted_results;
}

int main() {
    std::cout << std::boolalpha;
    std::string answer = removeDuplicate("geeksforgeeks");
    std::cout << (answer == "geksfor") << '\n';

    answer = removeDuplicate("codingminutes");
    std::cout << (answer == "codingmutes") << '\n';

    answer = removeDuplicate("greg was here");
}
