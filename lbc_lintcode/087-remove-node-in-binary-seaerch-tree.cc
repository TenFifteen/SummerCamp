/*
题目：25 % 删除二叉查找树的节点 困难

题目大意：
给定一个二叉查找树，删除其中某个节点

解题思路：
首先找到该节点。如果该节点没有左子树或者没有右子树，直接删除
如果该节点左右子树都有，则找到该节点的后继节点，交换val，然后删除该节点的后继节点。

遇到的问题：
感觉自己写的好麻烦，应该是从来没有写过类似的东西，实在是难看的自己都不想看了。

精彩解答：
http://hehejun.blogspot.com/2015/01/lintcoderemove-node-in-binary-search.html
看来我的思路是对的，只是写法有点繁琐。
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        auto pa = root;
        auto cur = root;
        while (cur != NULL && cur->val != value) {
            pa = cur;
            if (cur->val < value) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if (cur == NULL) return root;
        if (cur->left == NULL && cur->right == NULL) {
            if (cur == pa) {
                delete cur;
                return NULL;
            } else {
                if (pa->left == cur) pa->left = NULL;
                if (pa->right == cur) pa->right = NULL;
                delete cur;
                return root;
            }
        } else if (cur->left == NULL) {
            if (pa == cur) {
                auto ret = cur->right;
                delete cur;
                return ret;
            } else {
                if (pa->left == cur) {
                    pa->left = cur->right;
                    delete cur;
                    return root;
                } else {
                    pa->right = cur->right;
                    delete cur;
                    return root;
                }
            }
        } else if(cur->right == NULL) {
            if (pa == cur) {
                auto ret = cur->left;
                delete cur;
                return ret;
            } else {
                if (pa->left == cur) {
                    pa->left = cur->left;
                    delete cur;
                    return root;
                } else {
                    pa->right = cur->left;
                    delete cur;
                    return root;
                }
            }
        } else {
            auto old = cur;
            pa = cur;
            cur = cur->right;
            while (cur->left != NULL) {
                pa = cur;
                cur = cur->left;
            }
            swap(old->val, cur->val);
            if (pa->left == cur) {
                pa->left = cur->right;
                delete cur;
                return root;
            } else {
                pa->right = cur->right;
                delete cur;
                return root;
            }
        }
    }
};
