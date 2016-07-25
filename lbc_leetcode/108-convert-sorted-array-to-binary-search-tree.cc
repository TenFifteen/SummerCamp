/*
题目大意：
给定一个排好序的数组， 求出一个高度平衡的二叉树。

解题思路：
递归。

遇到的问题：
一次通过。

再次阅读：
基本没啥问题，递归求解就好。
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)return NULL;
        return sub(nums, 0, nums.size()-1);
    }

    TreeNode * sub(vector<int> &nums, int left, int right){
        if(left > right)return NULL;
        int mid = left + (right-left)/2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = sub(nums, left, mid-1);
        cur->right = sub(nums, mid+1, right);
        return cur;
    }
};
/*
第二次做：
简单题。
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
    TreeNode *build(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;

        int mid = left + ((right-left+1) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid-1);
        root->right = build(nums, mid+1, right);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return build(nums, 0, nums.size()-1);
    }
};
/*
 * some easy
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
    TreeNode *convert(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = convert(nums, left, mid-1);
        root->right = convert(nums, mid+1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return convert(nums, 0, nums.size()-1);
    }
};
