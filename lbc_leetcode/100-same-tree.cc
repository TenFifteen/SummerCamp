/*
题目大意：
判断两个二叉树而否是相同的。

解题思路：
如果两个二叉树是相同的，那么根节点的值相同，并且左子树与右子树分别相同。

遇到的问题：
一次通过。

再次阅读：
我也觉得应该是可以再简化一下代码的：
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL){
            if(q == NULL)return true;
            else return false;
        }
        if(q == NULL){
            if(p == NULL)return true;
            else return false;
        }
        if(p->val != q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};
/*
第二次做：
太简单的题目了。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL) return q == NULL;
        if (q == NULL) return p == NULL;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
/*
 * too easy
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return p == q;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
