/*
 * leetcode 20
 */
#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string str) {
        std::stack<char> s;
        for (const auto c : str) {
            // push on stack if opening bracket
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else {
                if (s.empty()) {
                    return false;
                }
                if (c == ')' && s.top() != '(') {
                    return false;
                }
                if (c == '}' && s.top() != '{') {
                    return false;
                }
                if (c == ']' && s.top() != '[') {
                    return false;
                }
                // matching brackets
                s.pop();
            }
        }
        return s.empty(); 
    }
};

int main() {
    Solution s;
    std::cout << std::boolalpha;
    std::cout << (s.isValid("()") == true) << '\n';
    std::cout << (s.isValid("()[]{}") == true) << '\n';
    std::cout << (s.isValid("(]") == false) << '\n';
    std::cout << (s.isValid("(") == false) << '\n';
    std::cout << (s.isValid("]") == false) << '\n';
}
