/*
题目大意：
线段树的修改。

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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == NULL || root->start > index || root->end < index) return;
        if (root->start == root->end) {
            root->max = value;
        } else {
            modify(root->left, index, value);
            modify(root->right, index, value);
            root->max = max(root->left->max, root->right->max);
        }
    }
};
