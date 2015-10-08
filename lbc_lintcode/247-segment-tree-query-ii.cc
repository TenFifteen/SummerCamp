/*
题目：28 % 线段树查询 II 中等

题目大意：
给定一个数组，问某个区间中有多少个数

解题思路：
线段树

遇到的问题：
没有问题。
*/
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == NULL) return 0;
        if (root->start >= start && root->end <= end) return root->count;
        if (root->start > end || root->end < start) return 0;
        return query(root->left, start, end) + query(root->right, start, end);
    }
};
