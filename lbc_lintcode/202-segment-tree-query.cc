/*
题目：34 % 线段树的查询 中等

题目大意：
给定一个线段树，查询某个区间内的最大值

解题思路：
递归查询

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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == NULL) return INT_MIN;
        if (root->start >= start && root->end <= end) return root->max;
        if (root->start > end || root->end < start) return INT_MIN;
        return max(query(root->left, start, end), query(root->right, start, end));
    }
};
