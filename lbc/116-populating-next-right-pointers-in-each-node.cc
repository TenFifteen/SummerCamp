/*
题目大意：
给定一个二叉树，完美二叉树。然后每个节点有一个指针，指向同一层的右边的兄弟。

解题思路：
递归。

遇到的问题；
没有问题。
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
        sub(root, NULL, NULL);
    }
    
    void sub(TreeLinkNode *root, TreeLinkNode *fa, TreeLinkNode *neigbor){
        if(root == NULL)return;
        if(fa == NULL){
            root->next = NULL;
        }else{
            if(fa->left == root){
                root->next = fa->right;
            }else{
                if(neigbor == NULL){
                    root->next = NULL;
                }else{
                    root->next = neigbor->left;
                }
            }
        }
        sub(root->left, root, root->next);
        sub(root->right, root, root->next);
    }
};