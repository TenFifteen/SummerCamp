/*
题目：二叉查找树中搜索区间 中等

题目大意：
给定一个二叉搜索树，查找区间[k1, k2]内的所有数，
并且按照升序排列

解题思路：
直接进行先序遍历，带条件的

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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> ans;
        sub(ans, root, k1, k2);
        return ans;
    }
    
    void sub(vector<int> &ans, TreeNode *root, int k1, int k2) {
        if (root == NULL) return;
        if (k1 > root->val) {
            sub(ans, root->right, k1, k2);
        } else if(k2 < root->val) {
            sub(ans, root->left, k1, k2);
        } else {
            sub(ans, root->left, k1, k2);
            ans.push_back(root->val);
            sub(ans, root->right, k1, k2);
        }
    }
};
