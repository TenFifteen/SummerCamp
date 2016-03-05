/*
题目大意：
给定一个二叉树，问从右边看是什么样子的。

解题思路：
按层遍历

遇到的问题：
几个笔误

再次阅读：
原来感觉上就是一个层次遍历。
但是看到DISCUSS中有人利用变形的先序遍历做的时候，感觉厉害极了，
说明三种顺序遍历并不是一成不变的，可以灵活使用才行：
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};
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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> cur;
        vector<int> ret;
        if(root == NULL)return ret;
        cur.push_back(root);
        while(cur.size() > 0){
            ret.push_back(cur[cur.size()-1]->val);
            vector<TreeNode*> next;
            for(auto c:cur){
                if(c->left != NULL){
                    next.push_back(c->left);
                }
                if(c->right != NULL){
                    next.push_back(c->right);
                }
            }
            cur = next;
        }
        return ret;
    }
};
/*
第二次做：
比较简单。
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
private:
    void view(TreeNode *root, vector<int> &ans, int level) {
        if (root == NULL) return;
        if (ans.size() == level) ans.push_back(root->val);
        ans[level] = root->val;
        view(root->left, ans, level+1);
        view(root->right, ans, level+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        view(root, ans, 0);
        return ans;
    }
};