#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(vector<int> &inorder, int l_in, int r_in, vector<int> &postorder, int l_post, int r_post)
{
    if (l_in > r_in) return NULL;

    int pos = 0;
    while (inorder[l_in+pos] != postorder[r_post])	pos++;

    TreeNode* now_root = new TreeNode(postorder[r_post]);
    now_root->left = dfs(inorder, l_in, l_in+pos-1, postorder, l_post, l_post+pos-1);
    now_root->right = dfs(inorder, l_in+pos+1, r_in, postorder, l_post+pos, r_post-1);

    return now_root;
}

/**
 * Problem: Given postorder and inorder traversal of a tree, construct the binary tree.
 * Solve: dfs
 * Tips: needn't construct now vector, just pass the position as parameters, because
 *       the data we need to pass is continuous
 */
TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if (n == 0) return NULL;

    return dfs(inorder, 0, n-1, postorder, 0, n-1);
}

int main()
{

    int n;
    while (cin >> n) {
        vector<int> inorder(n);
        vector<int> postorder(n);

        int temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            inorder[i] = temp;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            postorder[i] = temp;
        }

        TreeNode *root = buildTree(inorder, postorder);
    }

    return 0;
}

class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return sub(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
        }

        TreeNode *sub(vector<int> &in, vector<int> &post, int l1, int r1, int l2, int r2) {
            if (l1 > r1) return NULL;

            TreeNode *root = new TreeNode(post[r2]);

            int len = 0;
            while (in[l1+len] != root->val) ++len;

            root->left = sub(in, post, l1, l1+len-1, l2, l2+len-1);
            root->right = sub(in, post, l1+len+1, r1, l2+len, r2-1);

            return root;
        }
};
