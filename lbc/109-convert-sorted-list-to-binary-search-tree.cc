/*
题目大意：
给定一个排序的单链表，求出其一个高度平衡的二叉搜索树。

解题思路：
直接将单链表转化为数组，调用了108题的代码。

遇到的问题：
当然了也可以直接用链表做，但是那样每次都需要遍历链表，时间复杂度比较高。这样子虽然是空间复杂度高了一点，
但是可以大大的节约时间复杂度。
一次通过。

再次阅读：
竟然看到了一个用链表直接做，但是还效率很高的做法，实在是惊呆了：
class Solution {
public:
    ListNode *list;
    int count(ListNode *node){
        int size = 0;
        while (node) {
            ++size;
            node = node->next;
        }
        return size;
    }

    TreeNode *generate(int n){
        if (n == 0)
            return NULL;
        TreeNode *node = new TreeNode(0);
        node->left = generate(n / 2);
        node->val = list->val;
        list = list->next;
        node->right = generate(n - n / 2 - 1);
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        this->list = head;
        return generate(count(head));
    }
};
其实这种做法就类似于中序遍历，所以链表也就是访问了一遍就完了。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)return NULL;
        return sub(nums, 0, nums.size()-1);
    }
    
    TreeNode * sub(vector<int> &nums, int left, int right){
        if(left > right)return NULL;
        int mid = left + (right-left)/2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = sub(nums, left, mid-1);
        cur->right = sub(nums, mid+1, right);
        return cur;
    }
};