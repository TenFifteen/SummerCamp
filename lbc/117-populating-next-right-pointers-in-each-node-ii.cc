/*
题目大意：
给定一个普通的二叉树，将其每一层的节点从左到右连接起来。要求空间复杂度是常数。

解题思路：
利用当前层的next信息，可以将当前层当做链表来访问，然后就可以计算出下一层的next连接；
然后依次计算每一层。

遇到的问题：
如此说来，上一题也是做的不对了。既然要求是常数空间，就不应该有递归。

一开始我自己是想不到这个方法的，看了晚上别人的解答，感觉豁然开朗。
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)return;
        TreeLinkNode *head = root;
        TreeLinkNode *next = NULL;
        TreeLinkNode *cur = NULL;
        while(head != NULL){
            while(head != NULL){
                if(next == NULL){
                    if(head->left != NULL){
                        next = head->left;
                    }else if(head->right != NULL){
                        next = head->right;
                        head = head->next;
                    }else{
                        head = head->next;
                    }
                    cur = next;
                }else{
                    if(head->left == cur){
                        if(head->right != NULL){
                            cur->next = head->right;
                            cur = cur->next;
                            head = head->next;
                        }else{
                            head = head->next;
                        }
                    }else{
                        if(head->left == NULL){
                            if(head->right != NULL){
                                cur->next = head->right;
                                cur = cur->next;
                                head = head->next;
                            }else{
                                head = head->next;
                            }
                        }else{
                            cur->next = head->left;
                            cur = cur->next;
                        }
                    }
                }
            }
            head = next;
            next = NULL;
        }
    }
};