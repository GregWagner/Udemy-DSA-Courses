#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    std::cout << s.top() << '\n';
    s.pop();
    std::cout << s.top() << '\n';
    s.pop();

    std::cout << s.size() << '\n';
    std::cout << std::boolalpha << s.empty() << '\n';

    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << '\n' << s.size() << '\n';
}
