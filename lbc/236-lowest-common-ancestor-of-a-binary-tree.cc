/*
题目大意：
给定一个二叉树，两个节点。求两个节点的最低的共同祖先。

解题思路：
如果两个节点相同，就是自身。
如果某个节点等于root，就是root
如果某个子树中有两个节点，该祖先在该子树中；如果一个子树有一个节点，那么本节点就是
其最低的共同祖先。

遇到的问题：
没有问题。
不过感觉代码写的不是很简洁。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)return root;
        if(p == q)return p;
        return sub(root, p, q).first;
    }
    
    pair<TreeNode *, int> sub(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == NULL)return make_pair(root, 0);
        pair<TreeNode *, int> ret;
        if(root == p || root == q){
            ret.second = 1;
            ret.first = root;
            ret.second += sub(root->left, p, q).second;
            ret.second += sub(root->right, p, q).second;
            return ret;
        }
        auto left = sub(root->left, p, q);
        auto right = sub(root->right, p, q);
        if(left.second == 2)return left;
        if(right.second == 2)return right;
        if(left.second == 1 && right.second == 1)return make_pair(root, 2);
        return make_pair(root, left.second+right.second);
    }
};