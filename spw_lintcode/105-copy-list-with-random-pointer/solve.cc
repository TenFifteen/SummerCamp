/**
 * Problem: A linked list is given such that each node contains an additional
 *          random pointer which could point to any node in the list or null.
 *          Return a deep copy of the list.
 * Solve: dfs & hashmap
 * Tips: The return of dfs is a node pointer
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        /**
         * @param head: The head of linked list with a random pointer.
         * @return: A new head of a deep copy of the list.
         */
        RandomListNode *copyRandomList(RandomListNode *head) {
            unordered_map<int, RandomListNode *> nodes;
            return dfs(head, nodes);
        }

        RandomListNode *dfs(RandomListNode *head, unordered_map<int, RandomListNode *> &nodes) {
            if (head == NULL) return NULL;

            RandomListNode *now = new RandomListNode(head->label);
            nodes[head->label] = now;

            if (head->next) {
                if (nodes.find(head->next->label) != nodes.end()) {
                    now->next = nodes[head->next->label];
                } else {
                    now->next = dfs(head->next, nodes);
                }
            }

            if (head->random) {
                if (nodes.find(head->random->label) != nodes.end()) {
                    now->random = nodes[head->random->label];
                } else {
                    now->random = dfs(head->random, nodes);
                }
            }

            return now;
        }
};
