/*
题目：38 % 二叉树的后序遍历 容易

题目大意：
而定一个二叉树，求后序遍历，非递归

解题思路：
给每个节点标记是否已经访问过

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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        stack<pair<TreeNode *, bool>> stk;
        vector<int> ans;
        if (root == NULL) return ans;
        stk.push(make_pair(root, false));
        while (!stk.empty()) {
            auto cur = stk.top();      
            stk.pop();
            if (cur.second) {
                ans.push_back(cur.first->val);
            } else {
                cur.second = true;
                stk.push(cur);
                if (cur.first->right != NULL) stk.push(make_pair(cur.first->right, false));
                if (cur.first->left != NULL) stk.push(make_pair(cur.first->left, false));
            }
        }
        return ans;
    }
};
