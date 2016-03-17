/*
题目大意：
给定一个二叉树的中序和后续遍历，求先序遍历。

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
    TreeNode *build(vector<int> &in, int in_left, int in_right, 
                    vector<int> &post, int post_left, int post_right) {
        if (in_left > in_right) return NULL;
        int index = in_right;
        while (in[index] != post[post_right]) index--;
        
        TreeNode *root = new TreeNode(post[post_right]);
        root->left = build(in, in_left, index-1, post, post_left, post_left+index-in_left-1);
        root->right = build(in, index+1, in_right, post, post_left+index-in_left, post_right-1);
        return root;
    }
    
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.size() == 0) return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, inorder.size()-1);
    }
};