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
/*
第二次做：
比较简单的题目，不过一开始竟然用成了queue了。
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
        if (root == NULL) return ans;

        stack<TreeNode *> q;
        q.push(root);

        while (q.size()) {
            auto cur = q.top(); q.pop();
            ans.push_back(cur->val);
            if (cur->right) q.push(cur->right);
            if (cur->left) q.push(cur->left);
        }

        return ans;
    }
};
/*
 * very easy
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
        stack<TreeNode *> s;
        if (root != NULL) s.push(root);

        while (s.size() > 0) {
            TreeNode *cur = s.top(); s.pop();
            ans.push_back(cur->val);
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
        }
        return ans;
    }
};
