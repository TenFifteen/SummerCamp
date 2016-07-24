/*
题目大意：
给定一个二叉树，求出其根到叶子节点中的最短的路径。

解题思路：
递归

遇到的问题：
一开始没注意到叶子节点是left和right同时都是NULL的情况。。

再次阅读：
这个递归写的还是很漂亮的。
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
    int minDepth(TreeNode* root) {
        if(root == NULL)return NULL;
        if(root->left == NULL)return minDepth(root->right)+1;
        if(root->right == NULL)return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};
/*
第二次做：
简单题。
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL & root->right == NULL) return 1;
        if (root->left == NULL) return minDepth(root->right)+1;
        if (root->right == NULL) return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};
/*
 * some easy
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int ret = INT_MAX;
        if (root->left) ret = min(minDepth(root->left), ret);
        if (root->right) ret = min(minDepth(root->right), ret);
        return ret+1;
    }
};
