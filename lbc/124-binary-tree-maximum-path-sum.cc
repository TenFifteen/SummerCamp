/*
题目大意：
给定一个二叉树，求出树上的任意一条路径，其和最大。

解题思路：
递归。存在两种情况。一个是最大值包含root节点，一个是在两个子树中。

遇到的问题：
各种问题，调了好一会。
感觉这种题目需要加强训练，思维不够清晰。

再次阅读：
虽然思路相同，但是人家这种写法明显的简洁很多。
public class Solution {
    int maxValue;

    public int maxPathSum(TreeNode root) {
        maxValue = Integer.MIN_VALUE;
        maxPathDown(root);
        return maxValue;
    }

    private int maxPathDown(TreeNode node) {
        if (node == null) return 0;
        int left = Math.max(0, maxPathDown(node.left));
        int right = Math.max(0, maxPathDown(node.right));
        maxValue = Math.max(maxValue, left + right + node.val);
        return Math.max(left, right) + node.val;
    }
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
    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;
        auto ret = sub(root);
        return ret.second;
    }
    
    pair<int, int> sub(TreeNode *root){
        pair<int, int> ret;
        if(root->left == NULL && root->right == NULL){
            return make_pair(root->val, root->val);
        }
        if(root->left == NULL){
            auto right = sub(root->right);
            ret.first = max(root->val+right.first, root->val);
            ret.second = max(ret.first, right.second);
        }else if(root->right == NULL){
            auto left = sub(root->left);
            ret.first = max(root->val+left.first, root->val);
            ret.second = max(ret.first, left.second);
        }else{
            auto left = sub(root->left);
            auto right = sub(root->right);
            ret.first = max(root->val, root->val + left.first);
            ret.first = max(ret.first, root->val + right.first);
            ret.second = max(left.second, right.second);
            int tmp = root->val;
            if(left.first > 0)tmp += left.first;
            if(right.first > 0)tmp += right.first;
            ret.second = max(ret.second, tmp);
        }
        return ret;
    }
};