/*
题目大意：
给定一个二叉搜索树。两个节点。求其共同的最低的祖先。

解题思路：
与236题类似。但是简单一点。因为可以通过val的大小判断两个节点是在左子树中还是右子树中。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q)return q;
        if(root == p || root == q)return root;
        return sub(root, p, q);
    }
    
    TreeNode *sub(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root->val == p->val || root->val == q->val)return root;
        if(root->val > p->val && root->val > q->val)return sub(root->left, p, q);
        if(root->val < p->val && root->val < q->val)return sub(root->right, p, q);
        return root;
    }
};