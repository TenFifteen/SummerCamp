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
