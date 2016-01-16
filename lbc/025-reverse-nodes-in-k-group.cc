/*
题目大意：
给一个链表，给一个数字k。以k个一组，进行翻转。

解题思路：
找出k个一组的链表，进行reverse。然后把每块连起来。

遇到的问题：
这种程序都是各种边界比较烦人，一定要注意处理了所有的边界情况。

再次阅读：
之前的解法虽然没有什么问题，但是看到DISCUSS中有一个更简洁的解法。还是挺好的。
不过他这里忘记了将申请的preheader delete掉了。
也可以申请栈空间，就不用手动释放了。
他的思路就是将当前元素插入到前面的已经反转的元素的前面。
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2 || head == NULL)return head;
        ListNode *last = NULL;
        ListNode *ret = NULL;
        while(true){
            ListNode *khead = head;
            bool ok = true;
            for(int i = 0; i < k ; ++i){
                if(head != NULL){
                    if(i == k-1){
                        ListNode *tmp = head;
                        head = head->next;
                        tmp->next = NULL;
                    }else{
                        head = head->next;
                    }
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                ListNode *tmp = khead;
                khead = reverse(khead);
                if(ret == NULL){
                    ret = khead;
                    last = tmp;
                }else{
                    last->next = khead;
                    last = tmp;
                }
            }
            else{
                if(ret == NULL)return khead;
                last->next = khead;
                break;
            }
        }
        return ret;
    }
    
    ListNode *reverse(ListNode *head){
        ListNode *last = head;
        head = head->next;
        last->next = NULL;
        while(head != NULL){
            ListNode *tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
};