/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Problem: swap the adjacent nodes in the list
 * Solve: swap them two by two, we must judge if the count of left nodes are less than 2
 *		  swap method:
 *		  1  ->  2  ->  3  ->  4  ->  5
 *		         pre    temp
 *		  1. pre->next = temp->next; (2->4)
 *		  2. temp->next = pre->next->next;(3->5)
 *		  3. pre->next->next = temp; (4->3)
 *		  then we have 
 *		  1  ->  2  ->  4  ->  3  ->  5
 *		         pre		   temp
 * Tips: step 1. and step 2. can exchange
 *		 head must be handled separately
 *
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    struct ListNode *temp = head, *pre = NULL;
    head = head->next;
    temp->next = head->next;
    head->next = temp;
    
    pre = temp;
    temp = temp->next;
    while (temp) {
        // if only left the node temp
        if (!temp->next) return head;
        
        pre->next = temp->next;
        temp->next = pre->next->next;
        pre->next->next = temp;
        
        pre = temp;
        temp = temp->next;
    }
    
    return head;
}
