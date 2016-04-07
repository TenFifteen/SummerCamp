/**
 * Problem: Given an integer array (index from 0 to n-1, where n is the size
 *          of this array), and an query list. Each query has two integers [start, end].
 *          For each query, calculate the minimum number between index start
 *          and end in the given array, return the result list.
 * Solve: interval tree
 * Tips: no
 */
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class SegTreeNode {
    public:
        int start, end;
        SegTreeNode *left, *right;
        int minEle;

        SegTreeNode(int start, int end, int minEle) {
            this->start = start;
            this->end = end;
            this->minEle = minEle;
            this->left = this->right = NULL;
        }
};

class Solution {

    SegTreeNode* _build(vector<int> &A, int start, int end) {
        if (start > end) return NULL;

        if (start == end) {
            return new SegTreeNode(start, end, A[start]);
        }

        int mid = (start + end) / 2;
        SegTreeNode *root = new SegTreeNode(start, end, 0);

        root->left = _build(A, start, mid);
        root->right = _build(A, mid+1, end);

        root->minEle = min(root->left->minEle, root->right->minEle);

        return root;
    }

    int _query(SegTreeNode *root, int start, int end) {
        if (root == NULL) return INT_MAX;

        if (end < root->start || start > root->end) return INT_MAX;
        if (start <= root->start && root->end <= end) return root->minEle;

        return min(_query(root->left, start, end), _query(root->right, start, end));
    }
    public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        SegTreeNode *root = _build(A, 0, A.size()-1);

        int n = queries.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            ans[i] = _query(root, queries[i].start, queries[i].end);
        }

        return ans;
    }
};
