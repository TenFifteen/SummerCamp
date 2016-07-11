/**
 * Problem: Given a binary tree, determine if it is a valid
 *          binary search tree;
 * Solve: use non-recursive in order traversal.
 * Tips: see the comments below.
 */
bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;

    stack<TreeNode*>  nodes;

    TreeNode* iter = root;
    int prev = 0;
    bool first = true;

    // there are two kind of nodes, the nodes in stack, and the nodes
    // to traverse.
    while (iter || !nodes.empty()) {
        while (iter) {
            nodes.push(iter);
            iter = iter->left;
        }

        iter = nodes.top();
        nodes.pop();

        // the first must be singled out.
        if (first) {
            prev = iter->val;
            first = !first;
        } else {
            if (iter->val <= prev) return false;
            else prev = iter->val;
        }

        iter = iter->right;

    }

    return true;

}

class Solution {
public:
// pass by reference
    bool sub(TreeNode* &prev, TreeNode *now) {
        if (now == NULL) return true;

        bool left = sub(prev, now->left);
        if (!left) return false;

        if (prev != NULL && prev->val >= now->val)
            return false;

        prev = now;
        return sub(prev, now->right);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return sub(prev, root);
    }
};
