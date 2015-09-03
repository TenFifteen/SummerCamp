/*
题目：42 % 二叉树的层次遍历 II 中等

题目大意：
按照层次遍历二叉树，但是下面的先遍历

解题思路：
跟上一题一样，但是最后将ans倒置一下。


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
        for (int i = 0; i < ans.size()/2; ++i) {
            ans[i].swap(ans[ans.size()-1-i]);
        }
        return ans;
    }
};
