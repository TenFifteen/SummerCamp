/*
题目：34 % Segmemt Tree Build II 中等

题目大意：
给定一个数组，建立一个线段树，表示线段内的最大值

解题思路：
递归建立

遇到的问题：
没有问题。
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
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.size() == 0) return NULL;
        return _build(A, 0, A.size()-1);
    }
    
private:
    SegmentTreeNode * _build(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            auto ret = new SegmentTreeNode(left, right, A[left]);
            return ret;
        }
        auto ret = new SegmentTreeNode(left, right, 0);
        ret->left = _build(A, left, (left+right)/2);
        ret->right = _build(A, (left+right)/2+1, right);
        ret->max = max(ret->left->max, ret->right->max);
        return ret;
    }
};
