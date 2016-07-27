#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Two elements of a binary search tree are
 *          swapped mistake. Recover the tree without changing
 *          its structure.
 * Solve: based in in-order traversal of binary tree.
 * Tips: see comments below.
 */
TreeNode *node1 = NULL;
TreeNode *node2 = NULL;
TreeNode *prev = NULL;

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);

    // do something block.
    // the first element we should save the prev
    if (node1 == NULL && prev->val >= root->val) {
        node1 = prev;

    }

    // the second element we should save the current value.
    // we should notice that: if the two element are adjacent, the two steps
    // will work out. But if the two element are not adjacent, this step will
    // be executed another time to update.
    if (node1 != NULL && prev->val >= root->val) {
        node2 = root;

    }

    // the one key point
    prev = root;

    inorder(root->right);

}

void recoverTree(TreeNode* root) {
    node1 = NULL;
    node2 = NULL;
    prev = new TreeNode(INT_MIN);

    inorder(root);

    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;

}


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
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL;
        sub(root, prev);

        if (node1 && node2)
            swap(node1->val, node2->val);
    }

    TreeNode *node1 = NULL, *node2 = NULL;
    void sub(TreeNode *now, TreeNode *&prev) {
        if (now == NULL) return;

        sub(now->left, prev);
        if (prev && prev->val > now->val)
            if (!node1) {
                node1 = prev;
                node2 = now;
            } else {
               node2 = now;
            }

        prev = now;
        sub(now->right, prev);
    }
};
