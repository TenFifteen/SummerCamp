/*
题目大意：
给定一个字符串，其中只包含()[]{}三种括号。问括号是否是完全匹配的？

解题思路：
用一个stack

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        unordered_map<char, char> hash;
        hash[')'] = '(';
        hash[']'] = '[';
        hash['}'] = '{';
        
        stack<char> stk;
        for (auto ch : s) {
            if (ch == ')' || ch == ']' || ch == '}') {
                if (stk.size() == 0 || stk.top() != hash[ch]) return false;
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        
        return stk.size() == 0;
    }
};