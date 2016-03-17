/*
题目大意：
后续遍历二叉树。

解题思路：
见代码。

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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> ans;
        stack<TreeNode *> s;
        if (root != NULL) s.push(root);
        
        while (s.size() > 0) {
            TreeNode *cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
        
        if (ans.size() > 0) {
            int left = 0, right = ans.size()-1;
            while (left < right) {
                swap(ans[left++], ans[right--]);
            }
        }
        
        return ans;
    }
};