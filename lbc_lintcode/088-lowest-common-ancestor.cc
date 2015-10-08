/*
题目：34 % 最近公共祖先 中等

题目大意：
在一个二叉树中，给定两个节点，求这两个节点的最低公共祖先。

解题思路：
用深度优先遍历，找到两个节点的父节点列表。然后一个一个比对。

遇到的问题：
没有问题。但是这个题目好像是一个很经典的题目，有很多种经典的解法，但是我只是用的最基本的一种方法。

精彩解答：
https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/03.03.md
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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        vector<TreeNode *> pa, pb;
        findParents(root, A, pa);
        findParents(root, B, pb);
        auto ret = root;
        for (int i = 0; i < min(pa.size(), pb.size()); ++i) {
            if (pa[i] == pb[i]) {
                ret = pa[i];
            } else {
                break;
            }
        }
        return ret;
    }
    
    bool findParents(TreeNode *root, TreeNode *x, vector<TreeNode *> &pa) {
        if (root == NULL) return false;
        if (root == x) {
            pa.push_back(x);
            return true;
        } else {
            pa.push_back(root);
            if (findParents(root->left, x, pa)) return true;
            if (findParents(root->right, x, pa)) return true;
            pa.pop_back();
            return false;
        }
    }
};
