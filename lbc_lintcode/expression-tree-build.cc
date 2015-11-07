/*
题目：19 % 表达树构造 困难

题目大意：
给定一个表达式，求出表达式树。

解题思路：
就是用一个栈来存放还没有判断的数字以及+-符号，然后遇到各种不同的情况
分别处理就行了。

遇到的问题：
首先就是&&优先级要比||的优先级高，这一点竟然让我出了一个错误。
然后是错误处理一开始以为不会有空的括号，结果还真有。
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
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        if (expression.size() == 0) return NULL;
        stack<ExpressionTreeNode *> stk;
        for (auto e : expression) {
            if (stk.empty()) {
                stk.push(new ExpressionTreeNode(e));
            } else {
                if ("(" == e) {
                    stk.push(new ExpressionTreeNode(e));
                } else if ("+" == e || "-" == e || "*" == e || "/" == e) {
                    stk.push(new ExpressionTreeNode(e));
                } else if (")" == e) {
                    stack<ExpressionTreeNode *> tmp;
                    while (stk.top()->symbol != "(") {
                        tmp.push(stk.top());
                        stk.pop();
                    }
                    auto del = stk.top();
                    stk.pop();
                    delete del;
                    if (tmp.size() == 0) continue;
                    auto cur = tmp.top();
                    tmp.pop();
                    while (tmp.size() > 0) {
                        auto op = tmp.top();
                        tmp.pop();
                        auto right = tmp.top();
                        tmp.pop();
                        op->left = cur;
                        op->right = right;
                        cur = op;
                    }
                    if (stk.size() > 0 && (stk.top()->symbol == "*" || stk.top()->symbol == "/")) {
                        auto op = stk.top();
                        stk.pop();
                        auto left = stk.top();
                        stk.pop();
                        op->left = left;
                        op->right = cur;
                        cur = op;
                    }
                    stk.push(cur);
                } else {
                    if (stk.top()->symbol == "*" || stk.top()->symbol == "/") {
                        auto op = stk.top();
                        stk.pop();
                        auto left = stk.top();
                        stk.pop();
                        auto right = new ExpressionTreeNode(e);
                        op->left = left;
                        op->right = right;
                        stk.push(op);
                    } else {
                        stk.push(new ExpressionTreeNode(e));
                    }
                }
            }
        }
        if (stk.size() == 0) {
            return NULL;
        }
        if (stk.size() == 1) {
            return stk.top();
        } else {
            stack<ExpressionTreeNode *> tmp;
            while (stk.size() > 0) {
                tmp.push(stk.top());
                stk.pop();
            }
            auto cur = tmp.top();
            tmp.pop();
            while (tmp.size() > 0) {
                auto op = tmp.top();
                tmp.pop();
                auto right = tmp.top();
                tmp.pop();
                op->left = cur;
                op->right = right;
                cur = op;
            }
            
            return cur;
        }
    }
};
