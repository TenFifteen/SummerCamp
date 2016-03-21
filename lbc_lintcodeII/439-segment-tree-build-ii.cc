/*
题目大意：
给定一个数组，构造一棵线段树，求区间最大值。

解题思路：
见代码。

遇到的问题：
没有。
*/
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
class Solution {
    SegmentTreeNode *build(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new SegmentTreeNode(left, left, A[left]);
        
        int mid = (left+right)/2;
        SegmentTreeNode *ret = new SegmentTreeNode(left, right, 0);
        ret->left = build(A, left, mid);
        ret->right = build(A, mid+1, right);
        ret->max = max(ret->left->max, ret->right->max);
        return ret;
    }
    
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.size() == 0) return NULL;
        return build(A, 0, A.size()-1);
    }
};