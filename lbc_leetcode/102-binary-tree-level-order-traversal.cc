/*
题目大意：
给一个二叉树，返回其分层遍历的结果。

解题思路：
队列

遇到的问题：
一次通过。

再次阅读：
虽然之前的想法没啥问题，但是至少应该写成非递归的呀。
然后看了一下DISCUSS，还真有一个不错的想法的代码：
vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        queue<TreeNode *> q;
        q.push(root);
        sub(ans, q);
        return ans;
    }

    void sub(vector<vector<int>> &ans, queue<TreeNode *> q){
        queue<TreeNode *> next;
        vector<int> ret;
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            ret.push_back(cur->val);
            if(cur->left != NULL)next.push(cur->left);
            if(cur->right != NULL)next.push(cur->right);
        }
        ans.push_back(ret);
        if(!next.empty()){
            sub(ans, next);
        }
    }
};
/*
第二次做：
简单题，没啥问题。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<int> cur;
            for (int i = 0; i < len; ++i) {
                TreeNode *f = q.front(); q.pop();
                cur.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            ans.push_back(cur);
        }

        return ans;
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (q.size() > 0) {
            int len = q.size();
            vector<int> cur;
            for (int i = 0; i < len; ++i) {
                TreeNode *node = q.front(); q.pop();
                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
