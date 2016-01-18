/*
题目大意：
先序遍历二叉树，不用递归。

解题思路：
用一个stack将需要访问的节点缓存住。

遇到的问题：
一次通过。

再次阅读：
比较简单，直接用一个栈就可以了。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            if(cur->right != NULL)s.push(cur->right);
            if(cur->left != NULL)s.push(cur->left);
        }
        return ans;
    }
};