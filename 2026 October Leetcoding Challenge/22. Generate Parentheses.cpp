class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) {
            return std::vector<std::string>{""};
        }
        std::vector<std::string> answer;
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            for (std::string leftString : generateParenthesis(leftCount)) {
                for (std::string rightString :
                     generateParenthesis(n - 1 - leftCount)) {
                    answer.push_back("(" + leftString + ")" + rightString);
                }
            }
        }
        return answer;
    }
};
