/*
题目：22 % 表达式求值 困难

题目大意：
给定一个表达式。求其值

解题思路：
用栈存放未决的操作数和操作符

遇到的问题：
要处理空括号等特殊情况。
*/
class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        if (expression.size() == 0) return 0;
        stack<string> stk;
        for (auto e : expression) {
            if (stk.size() == 0) {
                stk.push(e);
            } else if (e == "(" || e == "+" || e == "-" || e == "*" || e == "/") {
                stk.push(e);
            } else if (e == ")") {
                stack<string> tmp;
                while (stk.top() != "(") {
                    tmp.push(stk.top());
                    stk.pop();
                }
                stk.pop();
                if (tmp.size() > 0) {
                    int cur = cal_brackets(tmp);
                    stk.push(to_string(cur));
                    cal_mul(stk);
                }
            } else {
                stk.push(e);
                cal_mul(stk);
            }
        }
        if (stk.size() == 0) return 0;
        stack<string> tmp;
        while (stk.size() != 0) {
            tmp.push(stk.top());
            stk.pop();
        }
        return cal_brackets(tmp);
    }
    
    void cal_mul(stack<string> &stk) {
        string num2 = stk.top();
        stk.pop();
        if (stk.size() == 0 || stk.top() == "+" || stk.top() == "-" || stk.top() == "(") {
            stk.push(num2);
            return;
        }
        string op = stk.top();
        stk.pop();
        string num1= stk.top();
        stk.pop();
        int cur;
        if (op == "*") {
            cur = stoi(num1) * stoi(num2);
        } else {
            cur = stoi(num1) / stoi(num2);
        }
        stk.push(to_string(cur));
    }
    
    int cal_brackets(stack<string> &stk) {
        int ret = stoi(stk.top());
        stk.pop();
        while (stk.size() > 0) {
            string op = stk.top();
            stk.pop();
            int num = stoi(stk.top());
            stk.pop();
            if (op == "+") {
                ret += num;
            } else {
                ret -= num;
            }
        }
        return ret;
    }
};
