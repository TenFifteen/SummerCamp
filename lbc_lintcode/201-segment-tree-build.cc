/*
题目：36 % 线段树的构造 中等

题目大意：
构造线段树

解题思路：
按照线段树的定义，递归构造

遇到的问题：
没有问题。
*/
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end) return NULL;
        if (start == end) return new SegmentTreeNode(start, end);
        auto ret = new SegmentTreeNode(start, end);
        ret->left = build(start, (start+end)/2);
        ret->right = build((start+end)/2+1, end);
        return ret;
    }
};
