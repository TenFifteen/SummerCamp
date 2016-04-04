/**
 * Problem: Given an expression string array, return the Reverse Polish
 *          notation of this expression. (remove the parentheses)
 * Solve: use a stack and priority of the operators.
 * Tips: 1. judge the oprand.
 *       2. when the operator with the lower priority go to the stack, it
 *          will pop all the operators higher or equal to it.
 */
class Solution {
    bool isOprand(string num) {
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            if (num[i] < '0' || num[i] > '9')
                return false;
        }

        return true;
    }
    public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> ans;

        stack<string> ops;

        int n = expression.size();
        for (int i = 0; i < n; ++i) {
            if (isOprand(expression[i])) {
                ans.push_back(expression[i]);
            } else {
                // ")" has the last priority.
                if (expression[i] == ")") {
                    while (ops.top() != "(") {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.pop();
                } else if (expression[i] == "+" || expression[i] == "-") { // "+" "-" has the third priority
                    while (!ops.empty() && ops.top() != "(") {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(expression[i]);
                } else if (expression[i] == "*" || expression[i] == "/") {// "*" "/" has the second higher priority.
                    while (!ops.empty() && (ops.top() == "*" || ops.top() == "/" )) {
                        ans.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(expression[i]);
                } else {// "(" has the highest priority.
                    ops.push(expression[i]);
                }
            }
        }

        while (!ops.empty()) {
            ans.push_back(ops.top());
            ops.pop();
        }

        return ans;
    }
};
