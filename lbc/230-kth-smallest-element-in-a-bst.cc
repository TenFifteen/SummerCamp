/*
题目大意：
给定一个二叉查找树，问其第k小的数是多少？

解题思路：
判断左子树的个数。如果大于等于k，就在左子树中；
如果等于k-1，就是root；
要不然就是在右子树中。

遇到的问题：
一次通过。

再次阅读：
感觉之前的解法已经很不错了。
如果想要优化掉多次count的代价的话，可以采用某个标志，来标记当前是否找到了。然后是先遍历左子树，
再遍历右子树。其实就是一个中序遍历。
而且，中序遍历还可以实现为迭代的，参考前面做过的题目即可。
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
    int kthSmallest(TreeNode* root, int k) {
        int left = count(root->left);
        if(left >= k)return kthSmallest(root->left, k);
        if(left == k-1)return root->val;
        return kthSmallest(root->right, k-left-1);
    }
    
    int count(TreeNode *root){
        if(root == NULL)return 0;
        return 1 + count(root->left) + count(root->right);
    }
};