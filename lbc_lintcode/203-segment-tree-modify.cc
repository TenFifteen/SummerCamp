/*
题目：36 % 线段树的修改 中等

题目大意：
给定一个线段树，修改某个节点的值

解题思路：
递归修改

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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root->start == root->end) {
            root->max = value;
            return;
        }
        if (root->left->end >= index) {
            modify(root->left, index, value);
        } else {
            modify(root->right, index, value);
        }
        root->max = max(root->left->max, root->right->max);
    }
};
