// Sorting the characters of a string
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::string> v;
    v.push_back("greg was here");
    v.push_back("there was a time");

    for (size_t i {}; i < v.size(); ++i) {
        std::cout << v[i] << '\n';
        std::sort(v[i].begin(), v[i].end());
        std::cout << v[i] << '\n';
        std::cout << "--------------------\n";
    }

    std::string s = "hello world";
    std::sort(s.begin(), s.end());
    std::cout << s << '\n';
}
