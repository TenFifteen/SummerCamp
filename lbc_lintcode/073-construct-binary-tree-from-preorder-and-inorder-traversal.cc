/*
题目：28 % 前序遍历和中序遍历树构造二叉树 中等

题目大意：
给定一个二叉树的前序和中序遍历，构造二叉树

解题思路：
递归构造

遇到的问题：
没有问题。
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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (preorder.size() == 0)return NULL;
        return sub(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode *sub(vector<int> &pre, int p_l, int p_r, vector<int> &in, int in_l, int in_r) {
        if (p_l > p_r) return NULL;
        if (p_l == p_r) return new TreeNode(pre[p_l]);
        auto ret = new TreeNode(pre[p_l]);
        int index = in_l;
        while (in[index] != pre[p_l]) index++;
        ret->left = sub(pre, p_l+1, p_l+index-in_l, in, in_l, index-1);
        ret->right = sub(pre, p_l+index-in_l+1, p_r, in, index+1, in_r);
        return ret;
    }
};
]