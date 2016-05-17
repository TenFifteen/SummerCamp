/*
题目大意：
线段树的查询。

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
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (start <= root->start && end >= root->end) return root->max;
        if (root->start > end || root->end < start) return INT_MIN;
        return max(query(root->left, start, end), query(root->right, start, end));
    }
};
