/*
题目大意：
给定一个二叉树，两个节点。求两个节点的最低的共同祖先。

解题思路：
如果两个节点相同，就是自身。
如果某个节点等于root，就是root
如果某个子树中有两个节点，该祖先在该子树中；如果一个子树有一个节点，那么本节点就是
其最低的共同祖先。

遇到的问题：
没有问题。
不过感觉代码写的不是很简洁。

再次阅读：
之前的思路没有太大问题，代码的确不算是简洁的，可以参考一下下面这段比较简洁的代码：
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q);
        return left && right ? root : left ? left : right;
    }
};
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)return root;
        if(p == q)return p;
        return sub(root, p, q).first;
    }

    pair<TreeNode *, int> sub(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == NULL)return make_pair(root, 0);
        pair<TreeNode *, int> ret;
        if(root == p || root == q){
            ret.second = 1;
            ret.first = root;
            ret.second += sub(root->left, p, q).second;
            ret.second += sub(root->right, p, q).second;
            return ret;
        }
        auto left = sub(root->left, p, q);
        auto right = sub(root->right, p, q);
        if(left.second == 2)return left;
        if(right.second == 2)return right;
        if(left.second == 1 && right.second == 1)return make_pair(root, 2);
        return make_pair(root, left.second+right.second);
    }
};
/*
第二次做：
这次的思路跟之前不太一样了，不过也是挺好的。
DISCUSS中的思路也是可以借鉴的。
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
    bool findPath(TreeNode *root, TreeNode *q, vector<TreeNode *> &path) {
        if (root == NULL) return false;

        path.push_back(root);
        if (root == q) return true;
        if (findPath(root->left, q, path)) return true;
        if (findPath(root->right, q, path)) return true;
        path.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_path, q_path;
        findPath(root, p, p_path);
        findPath(root, q, q_path);

        int i = 0;
        while (i < p_path.size() && i < q_path.size() && p_path[i] == q_path[i]) i++;
        return p_path[i-1];
    }
};
/*
 * good
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        if (root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        if (left) return left;
        return right;
    }
};
