/*
题目大意：
给定一个二叉树，按照锯齿的形状遍历。

解题思路：
queue

遇到的问题：
没有。
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
        
        queue<TreeNode *> q;
        q.push(root);
        bool left2right = true;
        
        while (q.size() > 0) {
            int len = q.size();
            vector<int> now(len);
            
            for (int i = 0; i < len; ++i) {
                TreeNode *cur = q.front(); q.pop();
                if (left2right) now[i] = cur->val;
                else now[len-i-1] = cur->val;
                
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            
            left2right = !left2right;
            ans.push_back(now);
        }
        
        return ans;
    }
};