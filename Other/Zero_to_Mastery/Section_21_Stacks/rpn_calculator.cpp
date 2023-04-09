#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s; 

        for (const auto &op : tokens) {
            if (op == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            } else if (op == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a - b);
            } else if (op == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            } else if (op == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            } else {
                s.push(std::stoi(op));
            }
        }
        return s.top();
    }
};

int main() {
    Solution s;
    std::cout << std::boolalpha;
    std::vector<std::string> a {"2","1","+","3","*"};
    std::cout << (s.evalRPN(a) == 9) << '\n';
    std::vector<std::string> b {"4","13","5","/","+"};
    std::cout << (s.evalRPN(b) == 6) << '\n';
    std::vector<std::string> c {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << (s.evalRPN(c) == 22) << '\n';
}
