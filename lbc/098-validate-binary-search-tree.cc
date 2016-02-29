/*
题目大意：
给定一个二分查找树，判断是否合格。元素午重复。

解题思路：
递归判定。

遇到的问题：
一开始感觉题目并不是在考察边界，所以没实现。结果竟然真的有边界问题。
也就是说不管什么题目，只要是有边界风险的就要考虑到。

再次阅读：
虽然一开始是想的有一种方法就是按照中序遍历的方式来看一下是否符合，但是没有想到
像下面这样直接在遍历的过程中就解决的。
感觉下面这种代码实在是非常好呀：
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};
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
    bool isValidBST(TreeNode* root) {
        long long up = INT_MAX, low = INT_MIN;
        up++;
        low--;
        return sub(root, up, low);
    }
    
    bool sub(TreeNode *root, long long up, long long low){
        if(root == NULL)return true;
        if(root->val > low && root->val < up){
            return sub(root->left, root->val, low) && sub(root->right, up, root->val);
        }
        return false;
    }
};
/*
第二次做：
跟第一次的思路竟然是一样一样的。。。
还是DISCUSS中的代码思路比较好，直接利用中序遍历解决了。
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
    bool isValid(TreeNode *root, long long low, long long high) {
        if (root == NULL) return true;
        if (root->val <= low || root->val >= high) return false;
        return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        long long low = INT_MIN, high = INT_MAX;
        return isValid(root, low-1, high+1);
    }
};