/*
题目大意：
给定一个链表，链表中除了next指针，还有一个random指针，随机指向链表中的某个节点。
要求深复制一个链表出来。

解题思路：
先将每个节点double一下。
然后将random指针修改正确。
然后将链表一分为二。

遇到的问题：
各种指针修改次序问题，链表的确是容易搞错，一定要仔细的写关于链表的东西。

再次阅读：
这个题目感觉的确是这样做是最优的了。
其实有一个比较直观的解法，就是把每个节点都放到hash里面，然后就可以直接找到random指针了。但是
这样有需要额外的O(n)的空间复杂度。
不过下面的代码还是有些丑，回头再写的时候一定要写的好看一些。
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)return NULL;
        RandomListNode *tmp = head;
        while(tmp != NULL){
            RandomListNode *next = tmp->next;
            tmp->next = new RandomListNode(tmp->label);
            tmp = tmp->next;
            tmp->next = next;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp != NULL){
            if(tmp->random != NULL){
                tmp->next->random = tmp->random->next;
            }
            tmp = tmp->next->next;
        }
        RandomListNode *ret = head->next;
        RandomListNode *cur = ret;
        head->next = head->next->next;
        head = head->next;
        cur->next = NULL;
        while(head != NULL){
            cur->next = head->next;
            head->next = head->next->next;
            head = head->next;
            cur = cur->next;
            cur->next = NULL;
        }
        return ret;
    }
};
/*
第二次做：
思路完全没有问题，只是写的过程有点长，而且不是特别的熟练。
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

        RandomListNode *root = head;
        while (root) {
            auto next = root->next;
            root->next = new RandomListNode(root->label);
            root->next->next = next;
            root = next;
        }

        root = head;
        while (root) {
            if (root->random) {
                root->next->random = root->random->next;
            }
            root = root->next->next;
        }

        root = head->next;
        RandomListNode *tail = root;
        head->next = root->next;
        head = head->next;
        while (head) {
            tail->next = head->next;
            tail = tail->next;
            head->next = tail->next;
            head = head->next;
        }
        tail->next = NULL;

        return root;
    }
};
/*
 * old question, but good question
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

        RandomListNode *cur = head;
        while (cur) {
            RandomListNode *next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = next;
        }

        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        RandomListNode *ret = head->next;
        cur = ret;
        head->next = ret->next;
        head = head->next;
        while (head) {
            cur->next = head->next;
            cur = cur->next;
            head->next = head->next->next;
            head = head->next;
        }
        cur->next = NULL;
        return ret;
    }
};
