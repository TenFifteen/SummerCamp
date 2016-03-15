/*
题目大意：
给定二叉树先序和中序遍历，构造二叉树。

解题思路：
见代码。

遇到的问题：
没有。
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
    TreeNode *build(vector<int> &pre, int pre_left, int pre_right,
                    vector<int> &in, int in_left, int in_right) {
        if (pre_left > pre_right) return NULL;
        
        int index = in_left;
        while (in[index] != pre[pre_left]) index++;
        
        TreeNode *root = new TreeNode(pre[pre_left]);
        root->left = build(pre, pre_left+1, pre_left+index-in_left, in, in_left, index-1);
        root->right = build(pre, pre_left+index-in_left+1, pre_right, in, index+1, in_right);
        return root;
    }
    
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (preorder.size() == 0) return NULL;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};