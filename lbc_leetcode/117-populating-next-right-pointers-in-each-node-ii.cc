/*
题目大意：
给定一个普通的二叉树，将其每一层的节点从左到右连接起来。要求空间复杂度是常数。

解题思路：
利用当前层的next信息，可以将当前层当做链表来访问，然后就可以计算出下一层的next连接；
然后依次计算每一层。

遇到的问题：
如此说来，上一题也是做的不对了。既然要求是常数空间，就不应该有递归。

一开始我自己是想不到这个方法的，看了晚上别人的解答，感觉豁然开朗。

再次阅读：
看了一下DISCUSS中最好的解法，就是这个样子的。
看来当时参考的别人的方案也是参考的DISUCSS这种思路呗。
这种思路还是挺好的，就是相当于直接用横向的指针当做一个当前层次的链表，思路非常好。
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
/*
第二次做：
由于上一道题中已经知道了，这种题目，就是可以把next当做链表来用最好了。
所以就做出来了。
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
        if (root == NULL) return;

        while (root) {
            TreeLinkNode next(0), *pnext = &next;
            while (root) {
                if (root->left) {
                    pnext->next = root->left;
                    pnext = pnext->next;
                }
                if (root->right) {
                    pnext->next = root->right;
                    pnext = pnext->next;
                }
                root = root->next;
            }
            root = next.next;
        }
    }
};
/*
 * good question. did not remember it again.
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
        while (root) {
            TreeLinkNode *next = NULL, *head = NULL;
            while (root) {
                if (root->left) {
                    if (head == NULL) {
                        head = root->left;
                    } else {
                        next->next = root->left;
                    }
                    next = root->left;
                }
                if (root->right) {
                    if (head == NULL) {
                        head = root->right;
                    } else {
                        next->next = root->right;
                    }
                    next = root->right;
                }
                root = root->next;
            }
            root = head;
        }
    }
};
