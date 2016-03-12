/*
题目大意：
给定一棵排序二叉树，搜索所有在k1和k2区间内的节点，并且按照升序排列

解题思路：
中序遍历

遇到的问题：
一开始忘记了判断root->val是否满足条件了。。。
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
    void search(vector<int> &ans, TreeNode *root, int k1, int k2) {
        if (root == NULL) return;
        
        if (root->val >= k1) search(ans, root->left, k1, k2);
        if (root->val >= k1 && root->val <= k2) ans.push_back(root->val);
        if (root->val <= k2) search(ans, root->right, k1, k2);
    }
    
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> ans;
        search(ans, root, k1, k2);
        return ans;
    }
};