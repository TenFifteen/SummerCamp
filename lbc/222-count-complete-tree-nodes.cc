/*
题目大意：
给定一个完美二叉树，求其节点的个数。

解题思路：
先求出二叉树的高度。然后判断该二叉树是否是最后一层是满的，如果是满的，可以直接计算出结果。
要不然就递归的数子树的个数。

遇到的问题：
边界条件搞的不是很清楚。
一开始忘记了处理完全少了一层的情况。
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
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int d = 0;
        TreeNode *tmp = root;
        while(tmp != NULL){
            tmp = tmp->left;
            d++;
        }
        return sub(root, d);
    }
    
    int sub(TreeNode *root, int d){
        if(root == NULL)return 0;
        if(d == 1)return 1;
        TreeNode *tmp = root;
        for(int i = 0; i < d-2; ++i){
            tmp = tmp->right;
        }
        if(tmp->right != NULL)return (1 << d) - 1;
        
        tmp = root;
        for(int i = 0; i < d-2; ++i){
            tmp = tmp->left;
        }
        if(tmp->left == NULL)return (1 << (d-1))-1;
        
        else return 1 + sub(root->left, d-1) + sub(root->right, d-1);
    }
};