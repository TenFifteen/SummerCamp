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
/*
第二次做：
这次终于机制的想出来了反着遍历的方法了。
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
        if (root == NULL) return ans;

        stack<TreeNode *> s;
        s.push(root);
        while (s.size()) {
            auto cur = s.top(); s.pop();
            ans.push_back(cur->val);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }

        for (int i = 0; i < ans.size()/2; ++i) {
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};
/*
 * fun question
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
        if (root == NULL) return ans;

        stack<TreeNode *> s;
        s.push(root);
        while (s.size() > 0) {
            TreeNode *cur = s.top(); s.pop();
            ans.push_back(cur->val);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }

        int left = 0, right = ans.size()-1;
        while (left < right) {
            swap(ans[left++], ans[right--]);
        }
        return ans;
    }
};
