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
 * Problem: Implement a build method with a given array, so that we can create
 *          crate a corresponding segment tree with every node value represent
 *          the corresponding interval max value in the array, return root of
 *          the this segment tree.
 * Solve: Use a new method with start and end index.
 * Tips: no
 */
class Solution {
    public:
        /**
         *@param A: a list of integer
         *@return: The root of Segment Tree
         */
        SegmentTreeNode * build(vector<int>& A) {
            if (A.size() == 0) return NULL;

            buildIndex(A, 0, A.size()-1);
        }
    private:
        SegmentTreeNode *buildIndex(vector<int> &A, int start, int end) {
            SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);

            if (start == end) {
                root->max = A[start];
                return root;
            }

            int mid = start + (end - start) / 2;
            root->left = buildIndex(A, start, mid);
            root->right = buildIndex(A, mid+1, end);
            root->max = max(root->left->max, root->right->max);

            return root;
        }
};
