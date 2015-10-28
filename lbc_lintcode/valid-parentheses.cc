/*
题目：27 % 有效的括号序列 容易

题目大意：
给定一系列的括号，问是否是匹配的。

解题思路：
用stack存放左括号，然后匹配右括号。

遇到的问题：
一开始忘记了最后判断stack是否为空了。
*/
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> stk;
        unordered_map<char, char> um;
        um[')'] = '(';
        um[']'] = '[';
        um['}'] = '{';
        for (auto ch : s) {
            if (ch == '[' || ch == '{' || ch == '(') {
                stk.push(ch);
            } else {
                if (stk.empty()) {
                    return false;
                } else if (stk.top() != um[ch]) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        if (stk.empty()) {
            return true;
        }
        return false;
    }
};
