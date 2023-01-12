#include <iostream>

auto main() -> int {
    int e2 {};
    int s2 {};
    int e1 {};
    int s1 {};
    std::cout << "Enter 2 start/end intervals: ";
    std::cin >> s1 >> e1 >> s2 >> e2;

    bool has_intersection {};

    int s = std::max(s1, s2);
    int e = std::min(e1, e2);

    if (s < e) {
        has_intersection = true;
    }

    if (has_intersection) {
        std::cout << s << ' ' << e << '\n';
    } else {
        std::cout << "-1\n";
    }
}

/*
    s1        e1
        s2  e2
    s1        e1
  s2


*/