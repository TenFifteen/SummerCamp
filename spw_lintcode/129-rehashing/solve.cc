/**
 * Problem:The size of the hash table is not determinate at the very beginning.
 *         If the total size of keys is too large (e.g. size >= capacity / 10),
 *         we should double the size of the hash table and rehash every keys.
 *         Say you have a hash table looks like below:
 * Solve: just do it
 * Tips: can't inverse the link list
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
            int n = hashTable.size();

            int dn = n << 1;
            vector<ListNode*> ans(dn, NULL);

            for (int i = 0; i < n; ++i) {
                if (hashTable[i]) {
                    ListNode* it = hashTable[i];
                    while (it) {
                        ListNode *now = it;
                        it = it->next;

                        int key = (now->val % dn + dn) % dn;
                        now->next = NULL;

                        if (ans[key] == NULL) ans[key] = now;
                        else {
                            ListNode *prev = ans[key];
                            while (prev->next) prev = prev->next;
                            prev->next = now;
                        }
                    }
                }
            }

            return ans;
        }
};

