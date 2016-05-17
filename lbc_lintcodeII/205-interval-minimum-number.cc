/*
题目大意：
给定一个数组，求区间的最小值。

解题思路：
线段树。

遇到的问题：
没有。
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
class Solution { 
    struct SegmentTreeNode {
        int start, end, min;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e) {
            start = s;
            end = e;
            left = right = NULL;
        }
    };
    
    SegmentTreeNode* build(const vector<int> &A, int start, int end) {
        if (left > right) return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end) {
            root->min = A[start];
        } else {
            int mid = (start+end)/2;
            root->left = build(A, start, mid);
            root->right = build(A, mid+1, end);
            root->min = min(root->left->min, root->right->min);
        }
        return root;
    }
    
    int query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || start > root->end || end < root->start) return INT_MAX;
        if (root->start >= start && root->end <= end) return root->min;
        return min(query(root->left, start, end), query(root->right, start, end));
    }
    
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> ans(queries.size());
        SegmentTreeNode *root = build(A, 0, A.size()-1);
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = query(root, queries[i].start, queries[i].end);
        }
        return ans;
    }
};
