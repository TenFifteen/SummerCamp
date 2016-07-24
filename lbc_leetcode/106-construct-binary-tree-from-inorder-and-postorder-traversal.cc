/*
题目大意：
给定一个二叉树的中序遍历和后序遍历，重构二叉树。

解题思路：
递归。

遇到的问题：
一次通过。

再次阅读：
感觉跟上一个题目是一样的，但是DISCUSS里面还是有人做成了迭代的方式。
暂时先不管迭代的了，要是哪天需要了，再说吧。
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return sub(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode *sub(vector<int> &in, int in_left, int in_right, vector<int> &post, int post_left, int post_right){
        if(in_left > in_right)return NULL;
        TreeNode *cur = new TreeNode(post[post_right]);
        int index = in_left;
        while(in[index] != post[post_right])index++;
        cur->left = sub(in, in_left, index-1, post, post_left, post_left+index-in_left-1);
        cur->right = sub(in, index+1, in_right, post, post_left+index-in_left, post_right-1);
        return cur;
    }
};
/*
第二次做：
跟上一题差不多。
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
    TreeNode *build(vector<int> &inorder,   int ileft, int iright,
                    vector<int> &postorder, int pleft, int pright) {
        if (ileft > iright) return NULL;

        TreeNode *root = new TreeNode(postorder[pright]);
        int index = iright;
        while (inorder[index] != postorder[pright]) index--;

        root->left = build(inorder, ileft, index-1, postorder, pleft, pleft+index-ileft-1);
        root->right = build(inorder, index+1, iright, postorder, pleft+index-ileft, pright-1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
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
    TreeNode *build(vector<int> &inorder, int in_left, int in_right, vector<int> &postorder, int post_left, int post_right) {
        if (in_left > in_right) return NULL;

        TreeNode *root = new TreeNode(postorder[post_right]);

        int index = in_left;
        while (inorder[index] != postorder[post_right]) index++;

        root->left = build(inorder, in_left, index-1, postorder, post_left, post_left+index-in_left-1);
        root->right = build(inorder, index+1, in_right, postorder, post_left+index-in_left, post_right-1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
