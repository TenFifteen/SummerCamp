/**
 * Problem: Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *          Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Solve: Just maintain a number stack and pop two numbers when we encounter a operator.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param tokens The Reverse Polish Notation
         * @return the value
         */
        int evalRPN(vector<string>& tokens) {
            // Write your code here
            stack<int> nums;

            int ans = 0;
            int n = tokens.size();
            for (int i = 0; i < n; ++i) {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    int m = nums.top(); nums.pop();
                    int n = nums.top(); nums.pop();

                    if (tokens[i] == "+") nums.push(n+m);
                    else if (tokens[i] == "-") nums.push(n-m);
                    else if (tokens[i] == "*") nums.push(n*m);
                    else nums.push(n/m);
                } else {
                    nums.push(stoi(tokens[i]));
                }
            }

            return nums.top();
        }
};
