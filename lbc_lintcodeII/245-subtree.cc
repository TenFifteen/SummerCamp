/*
题目大意：
给定两棵树，判断T2是不是T1的一棵子树。

解题思路：
见代码。

遇到的问题：
一开始搞错了一个问题，子树必须是从某个节点开始全部相同，而不是中间一段就行了。
另外就是一开始把isSubtree写成了isSub，找了半天错误。
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
    bool isSub(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL || t2 == NULL) {
            return t2 == t1;
        }
        if (t1->val != t2->val) return false;
        return isSub(t1->left, t2->left) && isSub(t1->right, t2->right);
    }
    
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (isSub(T1, T2)) return true;
        if (T1 && (isSubtree(T1->left, T2) || isSubtree(T1->right, T2))) return true;
        return false;
    }
};