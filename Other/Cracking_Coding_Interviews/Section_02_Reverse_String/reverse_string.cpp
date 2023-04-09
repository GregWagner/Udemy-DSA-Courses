#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }

    void reverseString2(std::vector<char>& s) {
        int start {};
        int end = s.size() - 1;
        while (start < end) {
            std::swap(s[start], s[end]);
            ++start;
            --end;
        }
    }

    // uses o(n) space
    void reverseString1(std::vector<char>& s) {
        std::stack<char> stack;
        for (auto c : s) {
            stack.push(c);
        }

        for (int i {}; i < s.size(); ++i) {
            s[i] = stack.top();
            stack.pop();
        }
    }
};

int main() {
    Solution s;
    std::vector<char> a {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(a);
    std::vector<char> a1 {'H', 'a', 'n', 'n', 'a', 'h'};
    s.reverseString(a1);
}
