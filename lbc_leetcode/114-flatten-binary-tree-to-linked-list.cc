/*
题目大意：
给定一个二叉树，求出将其flatten成一个链表。
按照先序遍历的顺序

解题思路：
递归

遇到的问题：
记得左右节点的左子树都要置为NULL

再次阅读：
感觉想到了一个比现在这种方法好一些的方法：就是用先序遍历，然后记录pre阶段，并且将pre的left指向
当前节点，这样做完了一遍先序遍历之后呢，就是一个向左偏的链表。
然后再遍历一遍，将其改为向右偏的链表即可。

然后呢，在DISCUSS中还找到了一种非递归的方式来实现的，感觉碉堡了：
void flatten(TreeNode *root) {
    while (root) {
        if (root->left && root->right) {
            TreeNode* t = root->left;
            while (t->right)
                t = t->right;
            t->right = root->right;
        }

        if(root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}
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
    void flatten(TreeNode* root) {
        sub(root);
    }

    TreeNode *sub(TreeNode *root){
        if(root == NULL)return NULL;
        TreeNode *left = NULL, *right = NULL;
        if(root->left != NULL){
            left = sub(root->left);
        }
        if(root->right != NULL){
            right = sub(root->right);
        }
        root->left = NULL;
        root->right = NULL;
        if(left != NULL){
            root->right = left;
        }
        TreeNode *cur = root;
        while(cur->right != NULL)cur = cur->right;
        cur->right = right;
        return root;
    }
};
/*
第二次做：
感觉上知道怎么做，但是写出来的代码不是很简洁。
还是DISCUSS中的思路比较简洁明了啊。
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
private:
    pair<TreeNode *, TreeNode *> sub(TreeNode *root) {
        TreeNode *left = root->left, *right = root->right;
        root->left = NULL;

        if (left == NULL && right == NULL) return make_pair(root, root);
        if (right == NULL) {
            auto L = sub(left);
            root->right = L.first;
            return make_pair(root, L.second);
        } else if (left == NULL) {
            auto R = sub(right);
            root->right = R.first;
            return make_pair(root, R.second);
        } else {
            auto L = sub(left), R = sub(right);
            root->right = L.first;
            L.second->right = R.first;
            return make_pair(root, R.second);
        }
    }

public:
    void flatten(TreeNode* root) {
        if (root != NULL) {
            sub(root);
        }
    }
};
/*
 * it's ok
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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        stack<TreeNode *> stk;
        while (root) {
            if (root->left != NULL) {
                if (root->right != NULL) stk.push(root->right);
                root->right = root->left;
                root->left = NULL;
            } else if (root->right == NULL) {
                if (stk.size() > 0) {
                    root->right = stk.top();
                    stk.pop();
                }
            }
            root = root->right;
        }
    }
};
