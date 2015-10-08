/*
题目：24 % 重哈希 中等

题目大意：
给定一个hash数组，现在将其夸大一倍

解题思路：
直接做

遇到的问题：
负数取模问题比较坑。
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
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        vector<ListNode *> ret(hashTable.size()*2, NULL);
        int n = ret.size();
        for (auto h : hashTable) {
            while (h != NULL) {
                auto next = h->next;
                h->next = NULL;
                int val = h->val;
                while (val < 0) val += n;
                int index = val % n;
                if (ret[index] == NULL) {
                    ret[index] = h;
                } else {
                    auto cur = ret[index];
                    while (cur->next != NULL) {
                        cur = cur->next;
                    }
                    cur->next = h;
                }
                h = next;
            }
        }
        return ret;
    }
};

