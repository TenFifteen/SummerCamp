/*
题目大意：
构造出所有的1-n的BST

解题思路：
见代码。

遇到的问题：
没有。
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
    void deleteTree(TreeNode *root) {
        if (root == NULL) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    
    TreeNode *deepcopy(TreeNode *root) {
        if (root == NULL) return root;
        TreeNode *ret = new TreeNode(root->val);
        ret->left = deepcopy(root->left);
        ret->right = deepcopy(root->right);
        return ret;
    }
    
    vector<TreeNode *> sub(int left, int right) {
        if (left > right) {
            return vector<TreeNode *>(1, NULL);
        }
        
        vector<TreeNode *> ret;
        for (int i = left; i <= right; ++i) {
            auto L = sub(left, i-1);
            auto R = sub(i+1, right);
            for (auto a : L) {
                for (auto b : R) {
                    TreeNode *root = new TreeNode(i);
                    root->left = deepcopy(a);
                    root->right = deepcopy(b);
                    ret.push_back(root);
                }
            }
            
            for (auto a : L) deleteTree(a);
            for (auto a : R) deleteTree(a);
        }
        return ret;
    }
    
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return sub(1, n);
    }
};
