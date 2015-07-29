/*
题目大意：
给定一个二分查找树，判断是否合格。元素午重复。

解题思路：
递归判定。

遇到的问题：
一开始感觉题目并不是在考察边界，所以没实现。结果竟然真的有边界问题。
也就是说不管什么题目，只要是有边界风险的就要考虑到。
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
    bool isValidBST(TreeNode* root) {
        long long up = INT_MAX, low = INT_MIN;
        up++;
        low--;
        return sub(root, up, low);
    }
    
    bool sub(TreeNode *root, long long up, long long low){
        if(root == NULL)return true;
        if(root->val > low && root->val < up){
            return sub(root->left, root->val, low) && sub(root->right, up, root->val);
        }
        return false;
    }
};