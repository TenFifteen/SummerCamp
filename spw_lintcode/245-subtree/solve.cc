/**
 * Problem: You have two every large binary trees: T1, with millions of nodes, and T2,
 *          with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
 * Solve: use two sub routine and a global variable
 * Tips: no
 */
class Solution {
    bool ans;
    public:
    bool isIdentical(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL || t2 == NULL) return t1 == t2;

        return t1->val == t2->val && isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
    }

    void preOrder(TreeNode *t1, TreeNode *t2) {
        if (ans || t1 == NULL) return;

        if (isIdentical(t1, t2)) {
            ans = true;
            return;
        }

        preOrder(t1->left, t2);
        preOrder(t1->right, t2);
    }
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) return true;

        ans = false;
        preOrder(T1, T2);
        return ans;
    }
};
