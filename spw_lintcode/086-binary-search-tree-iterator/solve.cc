/**
 * Problem: Design an iterator over a binary search tree with the following rules:
 *          Elements are visited in ascending order (i.e. an in-order traversal)
 *          next() and hasNext() queries run in O(1) time in average.
 * Solve: non-recursive inorder traversal.
 * Tips: no
 */
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
    private:
        stack<TreeNode*> nodes;
    public:
        //@param root: The root of binary tree.
        BSTIterator(TreeNode *root) {
            while (root) {
                nodes.push(root);
                root = root->left;
            }
        }

        //@return: True if there has next node, or false
        bool hasNext() {
            return !nodes.empty();
        }

        //@return: return next node
        TreeNode* next() {
            TreeNode *now = nodes.top();
            nodes.pop();

            TreeNode *it = now->right;
            if (it) {
                while (it) {
                    nodes.push(it);
                    it = it->left;
                }
            }

            return now;
        }
};
