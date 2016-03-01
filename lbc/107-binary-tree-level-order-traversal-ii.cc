/*
题目大意：
给定一个二叉树，返回其按层遍历的结果。从叶子到跟的顺序

解题思路：
先按照从根到叶子的顺序写出结果，最后进行调整。

遇到的问题：
没有问题。

再次阅读：
感觉基本这么做已经很差不多了。
还有一种可能，就是先检查一下这棵树的深度，然后直接构造好结果数组，每次遍历到的
元素直接插入到相应的位置的后面即可。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode *> cur;
        if(root == NULL)return ans;
        cur.push_back(root);
        sub(ans, cur);
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<TreeNode *> cur){
        vector<int> ret;
        vector<TreeNode *> next;
        for(auto t:cur){
            ret.push_back(t->val);
            if(t->left != NULL)next.push_back(t->left);
            if(t->right != NULL)next.push_back(t->right);
        }
        ans.push_back(ret);
        if(next.size() != 0)sub(ans, next);
    }
};
/*
第二次做：
没啥问题，简单题。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        while (q.size() > 0) {
            int len = q.size();
            vector<int> cur;
            for (int i = 0; i < len; ++i) {
                TreeNode *t = q.front(); q.pop();
                cur.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            
            ans.push_back(cur);
        }
        
        for (int i = 0; i < ans.size()/2; ++i) {
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};