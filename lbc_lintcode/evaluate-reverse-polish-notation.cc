/*
题目：26 % 逆波兰表达式求值 中等

题目大意：
给定一个逆波兰表达式，求其值。

解题思路：
用栈存放未决的操作数。

遇到的问题：
一开始超时了，太二了。
*/
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> stk;
        unordered_set<string> us;
        us.insert("+");
        us.insert("-");
        us.insert("*");
        us.insert("/");
        for (auto s : tokens) {
            if (us.find(s) == us.end()) {
                stk.push(stoi(s));
            } else {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                switch (s[0]) {
                    case '+':
                        stk.push(left+right);
                        break;
                    case '-':
                        stk.push(left-right);
                        break;
                    case '*':
                        stk.push(left*right);
                        break;
                    case '/':
                        stk.push(left/right);
                        break;
                }
            }
        }
        return stk.top();
    }
    
    int evalRPN2(vector<string>& tokens) {
        // Write your code here
        if (tokens.size() == 0) return 0;
        unordered_set<string> us;
        us.insert("+");
        us.insert("-");
        us.insert("*");
        us.insert("/");
        while (tokens.size() > 1) {
            vector<string> next;
            int i = 0;
            while (i < tokens.size() && us.find(tokens[i]) == us.end()) {
                next.push_back(tokens[i]);
                i++;
            }
            int right = stoi(next[next.size()-1]);
            next.pop_back();
            int left = stoi(next[next.size()-1]);
            next.pop_back();
            switch (tokens[i][0]) {
                case '+':
                    next.push_back(to_string(left+right));
                    break;
                case '-':
                    next.push_back(to_string(left-right));
                    break;
                case '*':
                    next.push_back(to_string(left*right));
                    break;
                case '/':
                    next.push_back(to_string(left/right));
                    break;
            }
            i++;
            while (i < tokens.size()) {
                next.push_back(tokens[i++]);
            }
            tokens.swap(next);
        }
        return stoi(tokens[0]);
    }
};
