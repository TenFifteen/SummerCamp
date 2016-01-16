/*
题目大意：
给一个二叉树，返回其深度。

解题思路：
递归。

遇到的问题：
一次通过。

再次阅读：
虽然之前的代码没啥问题，但是DISCUSS中总是有人写的更加简洁：
int maxDepth(TreeNode *root)
{
    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
另外，还可以通过BFS的迭代方式来计算最大深度。
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        return sub(root, 1);
    }
    
    int sub(TreeNode *root, int level){
        if(root == NULL)return level-1;
        return max(sub(root->left, level+1), sub(root->right, level+1));
    }
};