/*
题目大意：
判断两个二叉树而否是相同的。

解题思路：
如果两个二叉树是相同的，那么根节点的值相同，并且左子树与右子树分别相同。

遇到的问题：
一次通过。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL){
            if(q == NULL)return true;
            else return false;
        }
        if(q == NULL){
            if(p == NULL)return true;
            else return false;
        }
        if(p->val != q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};