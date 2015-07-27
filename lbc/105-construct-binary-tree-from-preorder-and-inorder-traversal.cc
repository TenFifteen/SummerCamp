/*
题目大意：
给定二叉树的前序遍历和中序遍历，求出二叉树。其中数字无重复。

解题思路：
递归。

遇到的问题：
没有问题。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)return NULL;
        return sub(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode * sub(vector<int> &pre, int pre_left, int pre_right, vector<int> &in, int in_left, int in_right){
        if(pre_left > pre_right)return NULL;
        TreeNode *cur = new TreeNode(pre[pre_left]);
        int index = in_left;
        while(in[index] != pre[pre_left])index++;
        cur->left = sub(pre, pre_left+1, pre_left+index-in_left, in, in_left, index-1);
        cur->right = sub(pre, pre_left+index-in_left+1, pre_right, in, index+1, in_right);
        return cur;
    }
};