/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
/**
 * Problem: Design a query method with three parameters root, start and end,
 *          find the number of elements in the in array's interval [start, end]
 *          by the given root of value SegmentTree.
 * Solve: use a subroutine to handle the main logic, and the invoke method to handle
 *        the boundary.
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         *@param root, start, end: The root of segment tree and an segment / interval
         *@return: The count number in the interval [start, end]
         */
        int query(SegmentTreeNode *root, int start, int end) {
            // boundary test
            if (root == NULL) return 0;
            if (end < root->start || start > root->end) return 0;

            // the given range may be larger than the range of segment tree.
            if (end > root->end) end = root->end;
            if (start < root->start) start = root->start;

            return count(root, start, end);
        }
    private:
        int count(SegmentTreeNode *root, int start, int end) {
            if (root->start == start && root->end == end) return root->count;

            // careful about mid
            int mid = root->start + (root->end - root->start) / 2;
            if (end <= mid) return query(root->left, start, end);
            else if (start > mid) return query(root->right, start, end);
            else return query(root->left, start, mid) + query(root->right, mid+1, end);
        }
};
