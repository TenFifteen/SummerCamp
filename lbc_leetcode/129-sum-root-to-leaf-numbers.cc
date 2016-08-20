/*
题目大意：
给定一个二叉树，从root到叶节点代表一个整数。求出所有的整数的和。

解题思路：
深度优先遍历。

遇到的问题：
一次通过。

再次阅读：
我觉得这种递归方式挺好的。
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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)return 0;
        return sub(0, root);
    }

    int sub(int fa, TreeNode *root){
        if(root->left == NULL && root->right == NULL){
            return fa*10 + root->val;
        }
        int ans = 0;
        if(root->left != NULL)ans += sub(fa*10+root->val, root->left);
        if(root->right != NULL)ans += sub(fa*10+root->val, root->right);
        return ans;
    }
};
/*
第二次做：
简单递归。
*/
/*
 * I find that second time, I did not post my code. Anyway, a little easy
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
private:
    int ans;
    void sub(TreeNode *root, int fa) {
        if (root->left == NULL && root->right == NULL) {
            ans += fa*10 + root->val;
            return;
        }

        if (root->left != NULL) sub(root->left, fa*10 + root->val);
        if (root->right != NULL) sub(root->right, fa*10 + root->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        ans = 0;
        sub(root, 0);
        return ans;
    }
};
