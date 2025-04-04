#include <iostream>
#include <string>

int main() {
    size_t largest_size{};
    std::string largest_string;

    std::string s;
    while (std::getline(std::cin, s)) {
        if (s.size() > largest_size) {
            largest_size = s.size();
            largest_string = s;
        }
    }
    std::cout << "Largest String was " << largest_string
        << ", which is " << largest_size << " characters long\n";
}
