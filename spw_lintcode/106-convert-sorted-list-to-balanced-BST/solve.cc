/**
 * Problem: Given a singly linked list where elements are sorted
 *          in ascending order, convert it to a height balanced BST.
 * Solve: count half
 * Tips: cut the list.
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
    int countList(ListNode *h) {
        int cnt = 0;
        while (h) {
            ++cnt;
            h = h->next;
        }

        return cnt;
    }
    public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;

        int n = countList(head);

        ListNode *half = head, *prev = head;
        n /= 2;
        while (n--) {
            prev = half;
            half = half->next;
        }

        TreeNode *root = new TreeNode(half->val);

        // left if not null;
        if (prev != half) {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }

        // right will probably be null, but the
        // first statement will handle.
        root->right = sortedListToBST(half->next);
        return root;
    }

};
