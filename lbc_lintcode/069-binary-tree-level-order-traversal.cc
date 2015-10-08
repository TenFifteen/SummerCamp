/*
题目：32 % 二叉树的层次遍历 中等

题目大意：
给定一个二叉树，按照层次访问

解题思路：
直接记录每层的节点

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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<TreeNode *> cur;
        cur.push_back(root);
        while (cur.size() != 0) {
            vector<TreeNode *> next;
            vector<int> tmp;
            for (auto c : cur) {
                tmp.push_back(c->val);
                if (c->left != NULL) next.push_back(c->left);
                if (c->right != NULL) next.push_back(c->right);
            }
            ans.push_back(tmp);
            cur.swap(next);
        }
        return ans;
    }
};

