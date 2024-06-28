#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<std::pair<int, int>>& a) {
    for (const auto& ele : a) {
        std::cout << ele.first << "," << ele.second << ' ';
    }
    std::cout << '\n';
}

int defkin(int width, int height, std::vector<std::pair<int, int>> position) {
    std::pair<int, int> first { 0, 0 };
    std::pair<int, int> last { width + 1, height + 1 };
    position.push_back(first);
    position.push_back(last);

    // determine the maximum x
    int max_x {};
    std::sort(begin(position), end(position));
    for (size_t i {}; i < position.size() - 1; ++i) {
        int current_size = position[i + 1].first - position[i].first - 1;
        max_x = std::max(max_x, current_size);
    }

    // determine the maximum y
    int max_y {};
    std::sort(begin(position), end(position),
        [](std::pair<int, int>& a, std::pair<int, int>& b) { return a.second < b.second; });
    for (size_t i {}; i < position.size() - 1; ++i) {
        int current_size = position[i + 1].second - position[i].second - 1;
        max_y = std::max(max_y, current_size);
    }

    return max_x * max_y;
}

int main() {
    std::vector<std::pair<int, int>> a {
        {3,   8},
        { 11, 2},
        { 8,  6}
    };
    std::cout << std::boolalpha;
    std::cout << (defkin(15, 8, a) == 12) << '\n';
}
