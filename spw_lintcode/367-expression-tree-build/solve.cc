/**
 * Problem: The structure of Expression Tree is a binary tree to evaluate certain expressions.
 *          All leaves of the Expression Tree have an number string value. All non-leaves of
 *          the Expression Tree have an operator string value.
 * Solve: use two stack and iterator from the end to the start
 * Tips: see comments below.
 */
/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    bool isOperand(string num) {
        int n = num.size();
        for (int i = 0; i < n; ++i)
            if (num[i] < '0' || num[i] > '9')
                return false;
        return true;
    }

    // leave out the boundary conditions aside, and after handle the right input
    // successfully. Then go back to handle the invalid input.
    void buildNode(stack<ExpressionTreeNode*> &expr, stack<string> &ops) {
        string op = ops.top(); ops.pop();

        ExpressionTreeNode* left = expr.top(); expr.pop();
        ExpressionTreeNode* right = expr.top(); expr.pop();

        ExpressionTreeNode* root = new ExpressionTreeNode(op);
        root->left = left; root->right = right;

        expr.push(root);
    }
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        stack<ExpressionTreeNode*> expr;
        stack<string> ops;

        int n = expression.size();
        for (int i = n-1; i >= 0; --i) {
            if (isOperand(expression[i])) {
                ExpressionTreeNode *leaf = new ExpressionTreeNode(expression[i]);
                expr.push(leaf);
            } else {
                if (expression[i] == "(") {
                    while (ops.top() != ")") buildNode(expr, ops);
                    ops.pop();
                } else if (expression[i] == "+" || expression[i] == "-") {
                    // must determine if it is empty before build a new node.
                    while (!ops.empty() && (ops.top() == "*" || ops.top() == "/")) buildNode(expr, ops);
                    ops.push(expression[i]);
                } else {
                    ops.push(expression[i]);
                }
            }
        }

        while (!ops.empty()) buildNode(expr, ops);

        // may be empty.
        return expr.empty() ? NULL : expr.top();
    }
};
