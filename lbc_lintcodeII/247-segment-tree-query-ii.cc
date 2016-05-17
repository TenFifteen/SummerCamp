/*
题目大意：
给定一个线段树，进行查询。

解题思路：
见代码。

遇到的问题：
没有。
*.
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
        if (root == NULL || root->start > end || root->end < start) return 0;
        if (root->start >= start && root->end <= end) return root->count;
        return query(root->left, start, end) + query(root->right, start, end);
    }
};
