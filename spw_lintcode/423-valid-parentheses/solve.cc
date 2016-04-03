/**
 * Problem: Given a string containing just the characters '(', ')',
 *          '{', '}', '[' and ']', determine if the input string is valid.
 * Solve: stack
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param s A string
         * @return whether the string is a valid parentheses
         */
        bool isValidParentheses(string& s) {
            stack<char> tokens;

            int n = s.size();
            for (int i = 0; i < n; ++i) {
                if (s[i] == ')' || s[i] == ']'|| s[i] == '}') {
                    if (tokens.empty()) return false;
                    if (s[i] == ')')  {
                        if (tokens.top() == '(') tokens.pop();
                        else return false;
                    } else if (s[i] == ']')  {
                        if (tokens.top() == '[') tokens.pop();
                        else return false;
                    } else {
                        if (tokens.top() == '{') tokens.pop();
                        else return false;
                    }
                } else {
                    tokens.push(s[i]);
                }
            }

            return tokens.empty();
        }
};
