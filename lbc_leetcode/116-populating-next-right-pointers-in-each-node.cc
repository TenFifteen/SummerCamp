/*
题目大意：
给定一个二叉树，完美二叉树。然后每个节点有一个指针，指向同一层的右边的兄弟。

解题思路：
递归。

遇到的问题；
没有问题。

再次阅读：
这次想到的是，按照层次遍历，但是依靠的是横向的链表，而不是一个队列了。
代码如下：
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
不过，我之前写的那个递归的版本也挺好的，跟这个思路也是类似的。
只不过，要是递归的空间复杂度也算进去的话，就不是一个常数的空间复杂度了。
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
/*
第二次做：
还是没有利用好链表这一个信息。。。
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
        if (root == NULL || root->left == NULL) return;

        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);
    }
};
/*
 * some easy
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
private:
    void sub(TreeLinkNode *root, TreeLinkNode *fa) {
        if (root == NULL) return;
        if (fa != NULL) {
            if (root == fa->left) {
                root->next = fa->right;
            } else if (fa->next != NULL) {
                root->next = fa->next->left;
            }
        }
        sub(root->left, root);
        sub(root->right, root);
    }

public:
    void connect(TreeLinkNode *root) {
        sub(root, NULL);
    }
};
