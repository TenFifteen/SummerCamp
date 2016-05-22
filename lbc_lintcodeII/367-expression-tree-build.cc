/*
题目大意：
给定一个表达式，求表达式树。

解题思路：
见代码。

遇到的问题：
见代码。
不知道这次这种思路是不是最优的，还需要参考一下之前的代码。
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
    ExpressionTreeNode *_build(const vector<string> &expression, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new ExpressionTreeNode(expression[left]);
        /*if (expression[right] == ")" && expression[left] == "(") {
            return _build(expression, left+1, right-1);
        } wrong for ()()*/
        
        int paranthese = 0;
        int last = -1;
        for (int i = right; i >= left; --i) {
            if (expression[i] == ")") paranthese++;
            else if (expression[i] == "(") paranthese--;
            if (paranthese == 0) {
                if (expression[i] == "+" || expression[i] == "-") {
                    last = i;
                    break;
                } else if (expression[i] == "*" || expression[i] == "/") {
                    if (last < 0) last = i;
                }
            }
        }
        
        if (last < 0) return _build(expression, left+1, right-1); // for (...)
        
        ExpressionTreeNode *root = new ExpressionTreeNode(expression[last]);
        root->left = _build(expression, left, last-1);
        root->right = _build(expression, last+1, right);
        return root;
    }
    
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        if (expression.size() == 0) return NULL;
        return _build(expression, 0, expression.size()-1);
    }
};
