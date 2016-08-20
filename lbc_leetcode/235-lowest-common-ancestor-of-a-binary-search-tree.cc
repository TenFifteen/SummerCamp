/*
题目大意：
给定一个二叉搜索树。两个节点。求其共同的最低的祖先。

解题思路：
与236题类似。但是简单一点。因为可以通过val的大小判断两个节点是在左子树中还是右子树中。

遇到的问题：
没有问题。

再次阅读：
没有太大问题，基本就是这么做了。
而且，这种做法也可以直接修改为迭代的。
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
        if(p == q)return q;
        if(root == p || root == q)return root;
        return sub(root, p, q);
    }

    TreeNode *sub(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root->val == p->val || root->val == q->val)return root;
        if(root->val > p->val && root->val > q->val)return sub(root->left, p, q);
        if(root->val < p->val && root->val < q->val)return sub(root->right, p, q);
        return root;
    }
};
/*
第二次做：
做的不错。
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
        if (root->val == p->val || root->val == q->val) return root;

        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
/*
 * good
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
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        if (left != NULL) return left;
        return right;
    }
};
