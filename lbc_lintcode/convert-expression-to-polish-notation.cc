/*
题目：23 % 将表达式转换为波兰表达式 困难

题目大意：
给定一个表达式，将其转化为波兰表达式

解题思路：
用表达式树，轻松搞定。

遇到的问题：
没有问题。
*/
class Solution {
    class ExpressionTreeNode {
    public:
        string symbol;
        ExpressionTreeNode *left, *right;
        ExpressionTreeNode(string symbol) {
            this->symbol = symbol;
            this->left = this->right = NULL;
        }
    };
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        // write your code here
        auto root = build(expression);
        return sub(root);
    }
    
    vector<string> sub(ExpressionTreeNode *root) {
        vector<string> ans;
        if (root == NULL) return ans;
        ans.push_back(root->symbol);
        auto left = sub(root->left);
        auto right = sub(root->right);
        for (auto l : left) {
            ans.push_back(l);
        }
        for (auto r : right) {
            ans.push_back(r);
        }
        return ans;
    }
    
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
