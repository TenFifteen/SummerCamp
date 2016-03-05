/**
 * Problem: The expression string contains only non-negative
 *          integers, +, -, *, / operators and empty spaces .
 * Solve: 1. calculate from the end to the begin.
 *        2. Before push '+', '-' we must pop all '*' and '/'
 * Tips: don't forget to push '+' or '-' after pop
 */
class Solution {
    private:
        int cal(stack<int> &operands, stack<char> &operators) {
            char op = operators.top(); operators.pop();
            int a = operands.top(); operands.pop();
            int b = operands.top(); operands.pop();
            if (op == '-') {
                operands.push(a - b);
            } else if(op == '+'){
                operands.push(a + b);
            } else if (op == '*') {
                operands.push(a * b);
            } else if (op == '/') {
                operands.push(a / b);
            }
        }
    public:
        int calculate(string s) {
            int n = s.size();
            if (n == 0) return 0;

            stack<int> operands;
            stack<char> operators;

            for (int i = n-1; i >= 0; --i) {
                if (s[i] == '*' || s[i] == '/') {
                    operators.push(s[i]);
                } else if (s[i] == '+' || s[i] == '-') {
                    while (operators.size() > 0 && (operators.top() == '*' || operators.top() == '/')) {
                        cal(operands, operators);
                    }
                    operators.push(s[i]);
                } else if (s[i] >= '0' && s[i] <= '9'){
                    string num = "";
                    while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
                        num = s[i] + num;
                        --i;
                    }
                    ++i;
                    operands.push(stoi(num));
                }
            }

            while (operators.size() > 0)
                cal(operands, operators);

            return operands.top();
        }
};
