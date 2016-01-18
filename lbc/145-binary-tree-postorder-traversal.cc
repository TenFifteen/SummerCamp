/*
题目大意：
给定一个二叉树，后序遍历，不能递归。

解题思路：
还是用stack将待访问的节点缓存住。

遇到的问题：
一次通过。

再次阅读：
虽然之前做过了，但是之前改变了输的结构，应该是不可以的。
然后去DISCUSS中看了一下大家做的，其实就是后序等于反着的先序（右子树先于左子树）
所以呢，就有了如下代码：
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> v;
    if (!root) return v;

    stack<TreeNode *> s;
    s.push(root);

    TreeNode *p = NULL;
    while(!s.empty()) {
        p = s.top();
        s.pop();
        v.insert(v.begin(), p->val);
        if (p->left) s.push(p->left);
        if (p->right) s.push(p->right);
    }

    return v;
}
当然了，这种插入数组的方式可能会效率低下。
也可以直接放到数组中，然后最后再翻转一下就行了。
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> s;
        if(root != NULL){
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = NULL;
            root->right = NULL;
            s.push(root);
            if(right != NULL)s.push(right);
            if(left != NULL)s.push(left);
        }
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            if(cur->left == NULL && cur->right == NULL){
                ans.push_back(cur->val);
            }else{
                TreeNode *left = cur->left;
                TreeNode *right = cur->right;
                cur->left = NULL;
                cur->right = NULL;
                s.push(cur);
                if(right != NULL)s.push(right);
                if(left != NULL)s.push(left);
            }
        }
        return ans;
    }
};