/*
题目大意：
给定二叉树的前序遍历和中序遍历，求出二叉树。其中数字无重复。

解题思路：
递归。

遇到的问题：
没有问题。

再次阅读：
是一个太经典的老题了。
但是竟然有人用了迭代的方式来解这个问题。
不过我觉得不是很有必要。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)return NULL;
        return sub(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode * sub(vector<int> &pre, int pre_left, int pre_right, vector<int> &in, int in_left, int in_right){
        if(pre_left > pre_right)return NULL;
        TreeNode *cur = new TreeNode(pre[pre_left]);
        int index = in_left;
        while(in[index] != pre[pre_left])index++;
        cur->left = sub(pre, pre_left+1, pre_left+index-in_left, in, in_left, index-1);
        cur->right = sub(pre, pre_left+index-in_left+1, pre_right, in, index+1, in_right);
        return cur;
    }
};
/*
第二次做：
比较简单。
不过如果面试遇到的话，一定要问一下面试官，是否要进行错误处理。感觉要是处理起来还是挺麻烦的。
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
    TreeNode *build(vector<int> &preorder, int pleft, int pright,
                    vector<int> &inorder,  int ileft, int iright) {
        if (pleft > pright) return NULL;
        
        TreeNode *root = new TreeNode(preorder[pleft]);
        int index = ileft;
        while (inorder[index] != preorder[pleft]) index++;
        
        root->left = build(preorder, pleft+1, pleft+index-ileft, inorder, ileft, index-1);
        root->right = build(preorder, pleft+index-ileft+1, pright, inorder, index+1, iright);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};