/*
题目大意：
给定一个二叉树，求出其所有路径中的和为sum的路径。

解题思路：
递归。

遇到的问题：
注意边界。

再次阅读：
感觉问题不大，基本就是这种思路，代码页差不多吧。
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<int> cur;
        sub(ans, cur, root, sum);
        return ans;
    }

    void sub(vector<vector<int>> &ans, vector<int> &cur, TreeNode *root, int sum){
        cur.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                ans.push_back(cur);
            }
        }
        if(root->left != NULL)sub(ans, cur, root->left, sum-root->val);
        if(root->right != NULL)sub(ans, cur, root->right, sum-root->val);
        cur.pop_back();
    }
};
/*
第二次做：
问题不是很大。
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
    void dfs(vector<vector<int> > &ans, vector<int> &now, TreeNode *root, int sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                now.push_back(root->val);
                ans.push_back(now);
                now.pop_back();
            }
            return;
        }

        now.push_back(root->val);
        dfs(ans, now, root->left, sum-root->val);
        dfs(ans, now, root->right, sum-root->val);
        now.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> now;
        dfs(ans, now, root, sum);
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
    void sub(vector<vector<int>> &ans, vector<int> &now, TreeNode *root, int sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                now.push_back(root->val);
                ans.push_back(now);
                now.pop_back();
            }
            return;
        }
        now.push_back(root->val);
        sub(ans, now, root->left, sum-root->val);
        sub(ans, now, root->right, sum-root->val);
        now.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> now;
        sub(ans, now, root, sum);
        return ans;
    }
};
