/*
题目：23 % 区间最小数 中等

题目大意：
给定一个数组，很多个查询，问区间内的最小值

解题思路：
用线段树

遇到的问题：
没有太多问题。
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
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        auto root = build(A, 0, A.size()-1);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = query(root, queries[i].start, queries[i].end);
        }
        return ans;
    }
    
private:
    struct SegmentTreeNode {
        int start, end, min;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e, int m) {
            left = right = NULL;
            start = s;
            end = e;
            min = m;
        }
    };
    
    SegmentTreeNode *build(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            auto ret = new SegmentTreeNode(left, right, A[left]);
            return ret;
        }
        auto ret = new SegmentTreeNode(left, right, 0);
        ret->left = build(A, left, (left+right)/2);
        ret->right = build(A, (left+right)/2+1, right);
        ret->min = min(ret->left->min, ret->right->min);
        return ret;
    }
    
    int query(SegmentTreeNode *root, int left, int right) {
        if (root == NULL) return INT_MAX;
        if (root->start >= left && root->end <= right) return root->min;
        if (root->start > right || root->end < left) return INT_MAX;
        return min(query(root->left, left, right), query(root->right, left, right));
    }
};
