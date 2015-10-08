/*
题目：30 % 中序遍历和后序遍历树构造二叉树 中等

题目大意：
根据二叉树的中序和后续遍历构造二叉树

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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.size() == 0) return NULL;
        return sub(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode *sub(vector<int> &inorder, int in_l, int in_r, vector<int> &postorder, int p_l, int p_r) {
        if (in_l > in_r) return NULL;
        if (in_l == in_r) return new TreeNode(inorder[in_l]);
        int index = in_l;
        while (inorder[index] != postorder[p_r]) index++;
        auto ret = new TreeNode(postorder[p_r]);
        ret->left = sub(inorder, in_l, index-1, postorder, p_l, p_l+index-in_l-1);
        ret->right = sub(inorder, index+1, in_r, postorder, p_l+index, p_r-1);
        return ret;
    }
};
