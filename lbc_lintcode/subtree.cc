/*
题目：20 % 子树 容易

题目大意：
给定两棵树，问T2是否是T1的子树

解题思路：
递归

遇到的问题：
一开始想错了。

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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) return true;
        if (T1 == NULL) return false;
        if (T1->val == T2->val) {
            return isSame(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
        } else {
            return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
        }
    }
    
    bool isSame(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL || T2 == NULL) return false;
        if (T1->val == T2->val) {
            return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
        }
        return false;
    }
    
    bool isSubtree2(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T2 == NULL) return true;
        if (T1 == NULL) return false;
        if (T1->val == T2->val) {
            if (isSubtree(T1->left, T2->left) && isSubtree(T1->right, T2->right)) {
                return true;
            } else if (isSubtree(T1->left, T2) || isSubtree(T1->right, T2)) {
                return true;
            } else {
                return false;
            }
        } else {
            if (isSubtree(T1->left, T2) || isSubtree(T1->right, T2)) {
                return true;
            } else {
                return false;
            }
        }
    }
};
