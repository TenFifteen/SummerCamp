#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given an binary tree contains digits from 0-9 only, find
 *          the total sum of all root-to-leaf numbers.
 * Solve: dfs
 * Tips: see the comments below
 */
void dfs(TreeNode* root, int &res, int prefix) {
    // only when the one branch is null
    if (root == NULL) return;
    int now = prefix * 10 + root->val;

    // if we count when the root == NULL, we will count the same path twice
    if (root->left == NULL && root->right == NULL) {
        res += now;
        return;

    }
    dfs(root->left, res, now);
    dfs(root->right, res, now);

}

int sumNumbers(TreeNode* root) {
    if (root == NULL) return 0;
    int res = 0;
    int prefix = 0;
    dfs(root, res, prefix);
    return res;

}
