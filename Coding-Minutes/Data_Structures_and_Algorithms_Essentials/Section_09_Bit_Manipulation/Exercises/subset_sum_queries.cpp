#include <bitset>
#include <iostream>
#include <vector>

std::vector<bool> subsetSum(std::vector<int> numbers, std::vector<int> query) {
    size_t n { query.size() };
    std::vector<bool> answer(n);

    std::bitset<10000> bit;
    bit.reset();
    bit[0] = 1;

    for (size_t i {}; i < numbers.size(); ++i) {
        bit |= (bit << numbers[i]);
    }

    for (size_t i {}; i < n; ++i) {
        answer[i] = (bit[query[i]] ? true : false);
    }
    return answer;
}

int main() {
    std::vector<int> numbers { 1, 2, 3 };
    std::vector<int> query { 5, 3, 8 };

    auto answer = subsetSum(numbers, query);
    std::cout << std::boolalpha;
    std::cout << "{ ";
    for (const auto& e : answer) {
        std::cout << e << ' ';
    }
    std::cout << "}\n";
}