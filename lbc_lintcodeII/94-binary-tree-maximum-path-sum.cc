/*
题目大意：
给定一棵二叉树，求其中最大的路径的和

解题思路：
见代码。

遇到的问题：
一开始NULL的时候，ret.first返回的是0，是有问题的。
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    pair<int, int> maxSum(TreeNode *root) {
        if (root == NULL) return make_pair(INT_MIN, 0);
        
        auto L = maxSum(root->left);
        auto R = maxSum(root->right);
        
        pair<int, int> ret;
        ret.first = root->val;
        if (L.second > 0) ret.first += L.second;
        if (R.second > 0) ret.first += R.second;
        ret.first = max(L.first, ret.first);
        ret.first = max(R.first, ret.first);
        
        ret.second = root->val;
        ret.second = max(ret.second, max(L.second, R.second)+root->val);
        
        return ret;
    }
    
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        return maxSum(root).first;
    }
};