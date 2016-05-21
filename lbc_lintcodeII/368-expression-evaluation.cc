/*
题目大意：
给定一个表达式，将其进行求值。

解题思路：
见代码。

遇到的问题：
一开始忘记了处理各种边界了。
后来是发现写错了处理()的逻辑了。
这次写还真是挺有收获的，虽然出了重大的bug，找了好久，但是这次会比较深刻的记住的。
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
        
        stack<string> ops;
        stack<int> nums;
        
        for (auto e : expression) {
            if (e == "+" || e == "-" || e == "*" || e == "/" || e == "(") {
                ops.push(e);
            } else if (e == ")") {
                /*while (ops.top() != "(") {
                    int right = nums.top(); nums.pop();
                    if (ops.top() == "+") nums.top() += right;
                    else nums.top() -= right;
                    ops.pop();
                }
                ops.pop(); this way will get wrong answer, just think about it.*/
                
                int now = 0;
                while (ops.top() != "(") {
                    if (ops.top() == "+") now += nums.top();
                    else now -= nums.top();
                    ops.pop();
                    nums.pop();
                }
                if (nums.size() > 0) nums.top() += now; // prevent ((()))
                ops.pop();
                
                while (ops.size() > 0 && (ops.top() == "*" || ops.top() == "/")) {
                    int right = nums.top(); nums.pop();
                    if (ops.top() == "*") nums.top() *= right;
                    else nums.top() /= right;
                    ops.pop();
                }
            } else {
                if (ops.size() > 0 && (ops.top() == "*" || ops.top() == "/")) {
                    if (ops.top() == "*") nums.top() *= stoi(e);
                    else nums.top() /= stoi(e);
                    ops.pop();
                } else {
                    nums.push(stoi(e));
                }
            }
        }
        
        while (ops.size() > 0) {
            int right = nums.top(); nums.pop();
            if (ops.top() == "+") nums.top() += right;
            else nums.top() -= right;
            ops.pop();
        }
        
        if (nums.size() == 0) return 0; // ((()))
        return nums.top();
    }
};
