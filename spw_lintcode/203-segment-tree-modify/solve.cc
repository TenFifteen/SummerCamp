/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

/**
 * Problem: For a Maximum Segment Tree, which each node has an extra value max
 *          to store the maximum value in this node's interval
 * Solve: recursive
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         *@param root, index, value: The root of segment tree and
         *@ change the node's value with [index, index] to the new given value
         *@return: void
         */
        void modify(SegmentTreeNode *root, int index, int value) {
            // boundary test, only work in the first access.
            if (root == NULL) return;
            if (index < root->start || index > root->end) return;

            // bottom
            if (root->start == root->end && root->start == index) {
                root->max = value;
                return;
            }

            // middle
            int mid = root->start + (root->end - root->start) / 2;
            if (index <= mid) {
                modify(root->left, index, value);
            } else {
                modify(root->right, index, value);
            }

            // key point
            root->max = max(root->right->max, root->left->max);
        }
};
