/*
题目大意：
给定一个表达式，将其转化为逆波兰表达式。

解题思路：
构造表达式树，然后直接遍历即可。

遇到的问题：
没有太大问题。
只不过这次构造表达式树又是用的一个比较偷懒的方法。
*/
class Solution {
    struct ExpressionTreeNode {
        string symbol;
        ExpressionTreeNode *left, *right;
        ExpressionTreeNode(string symbol) {
            this->symbol = symbol;
            this->left = this->right = NULL;
        }
    };
    
    ExpressionTreeNode *_build(vector<string> &expression, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new ExpressionTreeNode(expression[left]);
        //cout << left << " " << right << endl;
        int paranthes = 0;
        int last = -1;
        for (int i = right; i >= left; --i) {
            if (expression[i] == ")") paranthes++;
            else if (expression[i] == "(") paranthes--;
            else if (paranthes == 0) {
                if (expression[i] == "+" || expression[i] == "-") {
                    last = i;
                    break;
                } else if (expression[i] == "*" || expression[i] == "/") {
                    if (last < 0) last = i;
                }
            }
        }
        
        if (last < 0) return _build(expression, left+1, right-1);
        
        ExpressionTreeNode *root = new ExpressionTreeNode(expression[last]);
        root->left = _build(expression, left, last-1);
        root->right = _build(expression, last+1, right);
        return root;
    }
    
    void getAnswer(vector<string> &ans, ExpressionTreeNode *root) {
        if (root == NULL) return;
        
        ans.push_back(root->symbol);
        getAnswer(ans, root->right);
        getAnswer(ans, root->left);
    }
    
    void reverse(vector<string> &arr, int left, int right) {
        while (left < right) {
            swap(arr[left++], arr[right--]);
        }
    }
    
    void printTree(ExpressionTreeNode *root) { // for debug
        if (root == NULL) {
            cout << "#" << endl;
            return;
        }
        
        cout << root->symbol << endl;
        printTree(root->left);
        printTree(root->right);
    }
    
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        ExpressionTreeNode *root = NULL;
        if (expression.size() != 0) {
            root = _build(expression, 0, expression.size()-1);
        }//printTree(root);
        
        vector<string> ans;
        getAnswer(ans, root);
        
        if (ans.size() != 0) {
            reverse(ans, 0, ans.size()-1);
        }
        return ans;
    }
};
