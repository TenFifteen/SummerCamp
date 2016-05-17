/*
题目大意：
构造线段树。

解题思路：
见代码。

遇到的问题：
其实没有考虑溢出的情况。。
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
        
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end) return root;
        int mid = (start+end)/2;
        root->left = build(start, mid);
        root->right = build(mid+1, end);
        return root;
    }
};
