/*
 * Leetcode 1047
 */
#include <iostream>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeDuplicates(std::string str) {
        // simulate a stack in place
        int stackPtr {-1};
        for (size_t i {}; i < str.size(); ++i) {
            if (stackPtr == -1 || str[i] != str[stackPtr]) {
                ++stackPtr;
                str[stackPtr] = str[i];
            } else {
                --stackPtr;
            }
        }
        
        std::string results;
        for (int i {}; i <= stackPtr; ++i) {
            results.push_back(str[i]);
        }
        return results;

#if 0
        // This works but it is O(n) space
        std::stack<char> s;
        for (const auto c : str) {
            if (!s.empty() && s.top() == c) {
                s.pop();
            } else {
                s.push(c);
            }
        }

        std::string results;
        while (!s.empty()) {
            results.push_back(s.top());
            s.pop();
        }
        std::reverse(std::begin(results), std::end(results)); 
        return results;
#endif
    }
};

int main() {
    Solution s;
    std::cout << std::boolalpha;
    std::cout << (s.removeDuplicates("abbaca") == "ca") << '\n';
    std::cout << (s.removeDuplicates("azxxzy") == "ay") << '\n';
    std::cout << (s.removeDuplicates("mississippi") == "m") << '\n';
}
