/*
题目：24 % 区间求和 I 中等

题目大意：
给定一个数组，有一些查询，问区间的和

解题思路：
线段树

遇到的问题：
没有问题
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
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> ans(queries.size());
        auto root = build(A, 0, A.size()-1);
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = query(root, queries[i].start, queries[i].end);
        }
        return ans;
    }
    
private:
    struct SegmentTreeNode {
        int start, end;
        long long sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e, long long ss) {
            start = s;
            end = e;
            sum = ss;
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
        ret->sum = ret->left->sum + ret->right->sum;
        return ret;
    }
    
    long long query(SegmentTreeNode *root, int left, int right) {
        if (root == NULL) return 0;
        if (root->start >= left && root->end <= right) return root->sum;
        if (root->start > right || root->end < left) return 0;
        return query(root->left, left, right) + query(root->right, left, right);
    }
};
