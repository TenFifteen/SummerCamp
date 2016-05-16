/*
题目大意：
房屋抢劫，这次是一个二叉树形状的小区。

解题思路：
动规

遇到的问题：
没有。
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
    pair<int, int> sub(TreeNode *root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }
        auto left = sub(root->left);
        auto right = sub(root->right);
        
        pair<int, int> ret;
        ret.first = left.second + right.second + root->val;
        ret.second = max(left.first, left.second) + max(right.first, right.second);
        return ret;
    }
    
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        auto ret = sub(root);
        return max(ret.first, ret.second);
    }
};
