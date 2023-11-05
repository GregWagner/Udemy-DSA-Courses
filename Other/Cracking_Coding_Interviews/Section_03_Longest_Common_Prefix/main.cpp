#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    private:
        // function to compare string sizes to be used in std::min_element
        static bool cmp(std::string a, std::string b) {
            return a.size() < b.size();
        }

    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            std::string answer = "";
            if (strs.size()) {
                std::string smallestString = strs[0];
                for (unsigned i {}; i < smallestString.size(); ++i) {
                    for (unsigned j {1}; j < strs.size(); ++j) {
                        if (strs[j][i] != smallestString[i]) {
                            return answer;
                        }
                    }
                    answer += smallestString[i];
                }
            }
            return answer;
        }

        std::string longestCommonPrefix1(std::vector<std::string>& strs) {
            std::string answer = "";
            if (strs.size()) {
                // get the smallest string in the vector
                std::string smallestString = *std::min_element(strs.begin(),
                        strs.end(), cmp);
                for (unsigned i {}; i < smallestString.size(); ++i) {
                    for (auto str : strs) {
                        if (str[i] != smallestString[i]) {
                            return answer;
                        }
                    }
                    answer += smallestString[i];
                }
            }
            return answer;
        }
};
