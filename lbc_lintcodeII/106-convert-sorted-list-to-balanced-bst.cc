/*
题目大意：
给定一个排序的链表，将其转换为平衡二叉树

解题思路：
见代码。

遇到的问题：
没有。
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
    int count(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        
        int len = count(head);
        if (len == 1) {
            return new TreeNode(head->val);
        }
        
        ListNode *tail, *root = head;
        for (int i = 0; i < len/2; ++i) {
            tail = root;
            root = root->next;
        }
        
        TreeNode *ret = new TreeNode(root->val);
        
        tail->next = NULL;
        ret->left = sortedListToBST(head);
        ret->right = sortedListToBST(root->next);
        
        return ret;
    }
};


