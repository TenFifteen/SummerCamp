/**
 * Problem: Given an expression string array, return the final result of this expression
 * Solve: use two stack
 * Tips: priority and empty expression
 */
class Solution {
    bool isOprand(string nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] < '0' || nums[i] > '9')
                return false;
        return true;
    }

    void cal(stack<int> &nums, stack<string> &ops) {
        int a = nums.top(); nums.pop();
        int b = nums.top(); nums.pop();

        string op = ops.top(); ops.pop();
        if (op == "+") nums.push(b+a);
        else if (op == "-") nums.push(b-a);
        else if (op == "*") nums.push(b*a);
        else nums.push(b/a);
    }
    public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        stack<int> nums;
        stack<string> ops;

        int n = expression.size();
        for (int i = 0; i < n; ++i) {
            if (isOprand(expression[i])) {
                nums.push(stoi(expression[i]));
            } else {
                if (expression[i] == ")") {
                    while (ops.top() != "(") cal(nums, ops);
                    ops.pop();
                } else if (expression[i] == "+" || expression[i] == "-") {
                    while (!ops.empty() && ops.top() != "(") cal(nums, ops);
                    ops.push(expression[i]);
                } else if (expression[i] == "*" || expression[i] == "/") {
                    while (!ops.empty() && (ops.top() == "*" || ops.top() == "/")) cal(nums, ops);
                    ops.push(expression[i]);
                } else {
                    ops.push(expression[i]);
                }
            }
        }

        while (!ops.empty()) cal(nums, ops);

        return nums.empty() ? 0 : nums.top();
    }
};
