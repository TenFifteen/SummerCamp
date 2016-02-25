/*
题目大意：
给一个链表，将链表右移k位。

解题思路：
用两个指针，前后之间差k个。当后一个到达最后的时候，就是应该移动到前边去的那段。

遇到的问题：
一开始并没有想用两个指针。看到题目提示里竟然有，所以就这么用了。

再次阅读：
这次一下子就想到了两个指针的问题了。但是看了之前的代码，感觉之前写代码从来是没有
注释，没有空行。让人乍一看真不不太好看。所以以后刷题不光要注意解法，代码风格也是要注意
一下的。
下面这段代码是DISCUSS中的代码，虽然方法不太一样，但是可以借鉴一下：
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmp = head;
        int len = 0;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        if(len <= 1)return head;
        k %= len;
        if(k == 0)return head;
        ListNode *front = head;
        ListNode *end = head;
        for(int i = 0; i < k; ++i){
            front = front->next;
        }
        ListNode *last = NULL;
        while(front->next != NULL){
            front = front->next;
            last = end;
            end = end->next;
        }
        front->next = head;
        last = end->next;
        end->next = NULL;
        return last;
    }
};
/*
第二次做：
虽然这次写的比较顺利，还是没有想到DISCUSS那种思路，不过也还好，差不太多。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getListLen(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        int n = getListLen(head);
        k %= n;
        if (k == 0) return head;
        
        ListNode *cur = head, *last, *front = head, *frontLast;
        for (int i = 0; i < k; ++i) {
            frontLast = front;
            front = front->next;
        }
        while (front) {
            frontLast = front;
            front = front->next;
            last = cur;
            cur = cur->next;
        }
        
        frontLast->next = head;
        last->next = NULL;
        return cur;
    }
};