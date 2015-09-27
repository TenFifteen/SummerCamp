/*
题目：31 % 不同的二叉查找树 II 中等

题目大意：
给定一个n，求出所有的1-n数字的二叉查找树的结果

解题思路：
递归

遇到的问题：
没有问题。
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return sub(1, n);
    }
    
    vector<TreeNode *> sub(int left, int right) {
        vector<TreeNode *> ret;
        if (left > right) {
            ret.push_back(NULL);
            return ret;
        }
        if (left == right) {
            ret.push_back(new TreeNode(left));
            return ret;
        }
        for (int i = left; i <= right; ++i) {
            auto ret_l = sub(left, i-1);
            auto ret_r = sub(i+1, right);
            for (auto l : ret_l) {
                for (auto r : ret_r) {
                    auto head = new TreeNode(i);
                    head->left = l;
                    head->right = r;
                    ret.push_back(head);
                }
            }
        }
    }
};
