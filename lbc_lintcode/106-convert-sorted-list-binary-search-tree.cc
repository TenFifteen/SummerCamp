/*
题目：27 % 排序列表转换为二分查找树 中等

题目大意：
给定一个排序的链表。
将其转化为平衡二叉搜索树

解题思路：
递归

遇到的问题：
没有问题。
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int len = getLen(head);
        if (len == 0) return NULL;
        if (len == 1) return new TreeNode(head->val);
        if (len == 2) {
            auto ret = new TreeNode(head->next->val);
            ret->left = new TreeNode(head->val);
            return ret;
        }
        auto cur = head;
        auto last = head;
        for (int i = 0; i < (len-1)/2; ++i) {
            last = cur;
            cur = cur->next;
        }
        last->next = NULL;
        auto ret = new TreeNode(cur->val);
        ret->left = sortedListToBST(head);
        ret->right = sortedListToBST(cur->next);
        return ret;
    }
    
    int getLen(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            len++;
        }
        return len;
    }
};



