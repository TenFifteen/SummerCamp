/*
题目大意：
对你波兰表达式求值

解题思路：
用一个stack存放当前没有计算的数

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> s;
        
        for (auto t : tokens) {
            if (t == "*" || t == "/" || t == "+" || t == "-") {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                if (t == "*") s.push(left*right);
                else if (t == "/") s.push(left/right);
                else if (t == "+") s.push(left+right);
                else s.push(left-right);
            } else {
                s.push(stoi(t));
            }
        }
        
        return s.top();
    }
};