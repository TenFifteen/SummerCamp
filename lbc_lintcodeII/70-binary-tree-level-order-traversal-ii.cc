/*
题目大意：
给定一个二叉树，将二叉树按照层次进行遍历。从下往上。

解题思路：
直接从上往下层次遍历，然后反过来就行了。

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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (q.size() > 0) {
            int len = q.size();
            vector<int> tmp;
            for (int i = 0; i < len; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(tmp);
        }
        
        int left = 0, right = ans.size()-1;
        while (left < right) {
            swap(ans[left++], ans[right--]);
        }
        
        return ans;
    }
};