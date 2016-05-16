/*
题目大意：
给定一个哈希存储，实现rehash。简单的扩大两倍。

解题思路：
见代码。

遇到的问题：
感觉lintcode实在是有点挫啊。我只是把链表倒过来了，竟然就不认识了。。。
只能自己再写一个reverse了。。
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
 */
class Solution {
    ListNode *reverse(ListNode *head) {
        ListNode *ret = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = ret;
            ret = head;
            head = next;
        }
        
        return ret;
    }
    
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int n = hashTable.size() * 2;
        vector<ListNode *> ret(n, NULL);
        
        for (int i = 0; i < hashTable.size(); ++i) {
            if (hashTable[i] == NULL) continue;
            
            ListNode *head = hashTable[i];
            while (head) {
                ListNode *next = head->next;
                int key = (head->val % n + n) % n;
                head->next = ret[key];
                ret[key] = head;
                head = next;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            ret[i] = reverse(ret[i]);
        }
        
        return ret;
    }
};
