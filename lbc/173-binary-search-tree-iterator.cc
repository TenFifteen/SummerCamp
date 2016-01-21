/*
题目大意：
给定一个二叉搜索树，实现其迭代器的访问。

解题思路：
将待访问的节点放到stack中。

遇到的问题：
一开始将hasNext的真值搞反了。。
而且在next函数中，遇到的右子树的时候，忘记了将其所有的左子树都放进去了。

再次阅读：
一开始还真没有想到这种方法，虽然知道是用栈，就是细节没有想清楚。
这种方法还是很好的，DISCUSS中最好的也差不多就是这样。
最多就是再把那个while循环的内容放到一个单独的的函数中复用。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> sta;
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL){
            sta.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto cur = sta.top();
        sta.pop();
        auto tmp = cur->right;
        while(tmp != NULL){
            sta.push(tmp);
            tmp = tmp->left;
        }
        return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */