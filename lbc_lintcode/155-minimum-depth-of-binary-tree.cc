/*
题目：31 % 二叉树的最小深度 容易

题目大意：
给定一个二叉树，求其最小的叶子节点的深度

解题思路：
宽搜

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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        vector<TreeNode *> cur;
        int depth = 1;
        cur.push_back(root);
        while (cur.size() > 0) {
            vector<TreeNode *> next;
            for (auto t : cur) {
                if (t->left == NULL && t->right == NULL) return depth;
                if (t->left != NULL) next.push_back(t->left);
                if (t->right != NULL) next.push_back(t->right);
            }
            depth++;
            cur.swap(next);
        }
        return depth;
    }
};
