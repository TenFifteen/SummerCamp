/*
题目大意：
给定一个二叉树，问从右边看是什么样子的。

解题思路：
按层遍历

遇到的问题：
几个笔误
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> cur;
        vector<int> ret;
        if(root == NULL)return ret;
        cur.push_back(root);
        while(cur.size() > 0){
            ret.push_back(cur[cur.size()-1]->val);
            vector<TreeNode*> next;
            for(auto c:cur){
                if(c->left != NULL){
                    next.push_back(c->left);
                }
                if(c->right != NULL){
                    next.push_back(c->right);
                }
            }
            cur = next;
        }
        return ret;
    }
};