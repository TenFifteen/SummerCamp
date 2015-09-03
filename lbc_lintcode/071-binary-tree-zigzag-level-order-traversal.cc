/*
题目：28 % 二叉树的锯齿形层次遍历 中等

题目大意：
给定一个二叉树，第一层从左往右，下一层从右往左；这样锯齿形的遍历

解题思路：
只是将需要反着遍历的进行一次取反

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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<TreeNode *> cur;
        cur.push_back(root);
        bool left2right = true;
        while (cur.size() != 0) {
            vector<TreeNode *> next;
            vector<int> tmp;
            for (auto c : cur) {
                tmp.push_back(c->val);
                if (c->left != NULL) next.push_back(c->left);
                if (c->right != NULL) next.push_back(c->right);
            }
            if (!left2right) {
                left2right = true;
                for (int i = 0; i < tmp.size()/2; ++i) {
                    swap(tmp[i], tmp[tmp.size()-1-i]);
                }
            } else {
                left2right = false;
            }
            ans.push_back(tmp);
            cur.swap(next);
        }
        return ans;
    }
};
