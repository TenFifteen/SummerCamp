/*
题目大意：
给定一个二叉树，按照层次对其进行遍历

解题思路：
bfs

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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (q.size() > 0) {
            int len = q.size();
            vector<int> v(len);
            
            for (int i = 0; i < len; ++i) {
                TreeNode *cur = q.front(); q.pop();
                v[i] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};
