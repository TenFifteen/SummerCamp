/*
题目大意：
给出一个二叉树，进行中序遍历。要求不要递归。

解题思路：
用一个stack将需要后访问的节点存储起来。

遇到的问题：
我竟然用一个queue调试了老半天。
哎，真是挫啊。

再次阅读：
看了一下，觉得就是应该用一个栈来记录访问了左子树，但是自身和右子树都没有访问的元素。
而且应该有一个cur指针，用来表示当前应该处理的节点。如果当前没有应该处理的，可以去
stack中取一个处理了一半的。
看了一下DISCUSS中的解法，基本也都是用的栈。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;
        stack<TreeNode *> q;
        q.push(root);
        set<TreeNode *> s;
        while(!q.empty()){
            TreeNode *cur = q.top();
            q.pop();
            if(cur->left == NULL || s.count(cur) != 0){
                ans.push_back(cur->val);
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }else{
                q.push(cur);
                q.push(cur->left);
                s.insert(cur);
            }
        }
        return ans;
    }
};
/*
第二次做：
比较顺利，一次通过。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode *> stk;
        while (root->left) {
            stk.push(root);
            root = root->left;
        }
        stk.push(root);

        while (stk.size()) {
            TreeNode *cur = stk.top();stk.pop();
            ans.push_back(cur->val);
            cur = cur->right;
            if (cur) {
                while (cur->left) {
                    stk.push(cur);
                    cur = cur->left;
                }
                stk.push(cur);
            }
        }

        return ans;
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
private:
    void inorder(vector<int> &ans, TreeNode *root) {
        if (root == NULL) return;
        inorder(ans, root->left);
        ans.push_back(root->val);
        inorder(ans, root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(ans, root);
        return ans;
    }
};
