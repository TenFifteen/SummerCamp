/**
 * Problem: Given an integer array (index from 0 to n-1, where n is the size of
 *          this array), and an query list. Each query has two integers [start, end].
 *          For each query, calculate the sum number between index start and end
 *          in the given array, return the result list.
 * Solve: implement build and query.
 * Tips: don't mistake left/right pointer with start/end interval.
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
        long long sum;
        SegTreeNode *left, *right;

        SegTreeNode(int s, int e, long long sum) {
            this->start = s;
            this->end = e;
            this->sum = sum;
            this->left = this->right = NULL;
        }
};

class Solution {
    public:
        SegTreeNode *build(vector<int> &A, int start, int end) {
            if (start > end) return NULL;
            if (start == end) return new SegTreeNode(start, end, A[start]);

            int mid = (start + end) / 2;
            SegTreeNode* root = new SegTreeNode(start, end, 0);

            root->left = build(A, start, mid);
            root->right = build(A, mid+1, end);

            root->sum += root->left ? root->left->sum : 0;
            root->sum += root->right ? root->right->sum : 0;

            return root;
        }

        long long query(SegTreeNode *root, int start, int end) {
            if (start > end || root == NULL) return 0;

            if (root->start == start && root->end == end) return root->sum;

            int mid = (root->start + root->end) / 2;

            if (end <= mid)  return query(root->left, start, end);
            if (start > mid)  return query(root->right, start, end);

            return query(root->left, start, mid) + query(root->right, mid+1, end);
        }
        /**
         *@param A, queries: Given an integer array and an query list
         *@return: The result list
         */
        vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
            SegTreeNode *root = build(A, 0, A.size()-1);


            int n = queries.size();
            vector<long long> ans(n);

            for (int i = 0; i < n; ++i) {
                ans[i] = query(root, queries[i].start, queries[i].end);
            }

            return ans;
        }
};
