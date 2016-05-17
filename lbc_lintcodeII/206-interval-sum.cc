/*
题目大意：
区间和

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
        int start, end;
        long long sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e) {
            start = s;
            end = e;
            left = right = NULL;
        }
    };
    
    SegmentTreeNode *build(const vector<int> &A, int start, int end) {
        if (start > end) return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end) {
            root->sum = A[start];
        } else {
            int mid = (start + end)/2;
            root->left = build(A, start, mid);
            root->right = build(A, mid+1, end);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }
    
    long long query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || root->start > end || root->end < start) return 0;
        if (root->start >= start && root->end <= end) return root->sum;
        return query(root->left, start, end) + query(root->right, start, end);
    }
    
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentTreeNode *root = build(A, 0, A.size()-1);
        
        vector<long long> ans(queries.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = query(root, queries[i].start, queries[i].end);
        }
        return ans;
    }
};
