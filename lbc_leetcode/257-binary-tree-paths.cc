/*
题目大意：
给定一个二叉树，返回所有路径的字符串表示。

解题思路：
递归

遇到的问题：
没有问题。一次通过。

再次阅读：
简单题，递归即可。
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return vector<string>();

        auto rleft = binaryTreePaths(root->left);
        auto rright = binaryTreePaths(root->right);

        vector<string> ans;
        for (auto i : rleft) {
            ans.push_back(to_string(root->val) + "->" + i);
        }
        for (auto i : rright) {
            ans.push_back(to_string(root->val) + "->" + i);
        }

        if (ans.size() == 0) {
            ans.push_back(to_string(root->val));
        }
        return ans;
    }
};
/*
第二次做：
这次用的是跟第一次相对应的思路，其实差不多的，只是方向不同。
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
    void subPath(TreeNode *root, vector<string> &ans, string now) {
        if (root == NULL) return;
        now += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(now);
            return;
        }

        if (root->left != NULL) subPath(root->left, ans, now+"->");
        if (root->right != NULL) subPath(root->right, ans, now+"->");
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        subPath(root, ans, "");
        return ans;
    }
};
/*
 * ok
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
    void dfs(TreeNode *root, vector<string> &ans, string now) {
        if (now == "") now += to_string(root->val);
        else now += "->" + to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(now);
            return;
        }

        if (root->left) dfs(root->left, ans, now);
        if (root->right) dfs(root->right, ans, now);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;
        dfs(root, ans, "");
        return ans;
    }
};
