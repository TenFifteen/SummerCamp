/*
题目大意：
给定一个二叉搜索树，判断其是否是平衡的。

解题思路：
按照平衡二叉树的定义，任意一个树的左子树和右子树的高度差不能大于1。递归。

遇到的问题：
没有问题。

再次阅读：
感觉没啥问题。这样做挺好的。
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        auto ret = sub(root);
        return ret.second;
    }
    
    pair<int, bool> sub(TreeNode *root){
        if(root == NULL){
            return make_pair(0, true);
        }
        auto left = sub(root->left);
        auto right = sub(root->right);
        return make_pair(max(left.first, right.first)+1, left.second && right.second && abs(left.first-right.first) < 2);
    }
};