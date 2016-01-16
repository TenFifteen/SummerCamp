/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
/**
 * Problem: The structure of Segment Tree is a binary tree which each node has
 *          two attributes start and end denote an segment / interval.
 * Solve: recursive
 * Tips: no
 */
class Solution {
    public:
        /**
         *@param start, end: Denote an segment / interval
         *@return: The root of Segment Tree
         */
        SegmentTreeNode * build(int start, int end) {
            // write your code here
            if (start > end) return NULL;

            SegmentTreeNode *root = new SegmentTreeNode(start, end);
            if (start == end) return root;

            int mid = start + (end - start) / 2;
            root->left = build(start, mid);
            root->right = build(mid+1, end);

            return root;
        }
};
