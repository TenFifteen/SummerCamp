/*
题目：28 % 最大树 困难

题目大意：
给定一个数组，用这个数组建立一棵树。
要求最大的元素为根，两侧元素递归的成为其子树。

解题思路：
最直观的解法就是递归求解。
时间复杂度是n*n

然后有人说这就是笛卡尔树，虽然不知道啥是笛卡尔树。
就是建立一个stack，存放当前的所有递减的左子树。
如果遇到的比栈顶大的元素，则递归弹栈。

遇到的问题：
只是大体模糊的理解了。不是特别的清楚。回头还要好好看看。
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
     
    TreeNode *maxTree(vector<int> A) {
        if (A.size() == 0) return NULL;
        stack<TreeNode *> stk;
        stk.push(new TreeNode(A[0]));
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] < stk.top()->val) {
                stk.push(new TreeNode(A[i]));
            } else {
                auto cur = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top()->val < A[i]) {
                    auto tmp = stk.top();
                    stk.pop();
                    tmp->right = cur;
                    cur = tmp;
                }
                auto tmp = new TreeNode(A[i]);
                tmp->left = cur;
                stk.push(tmp);
            }
        }
        auto ret = stk.top();
        stk.pop();
        while (!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            tmp->right = ret;
            ret = tmp;
        }
        return ret;
    }

    TreeNode* maxTree2(vector<int> A) {
        // write your code here
        if (A.size() == 0) return NULL;
        return sub(A, 0, A.size()-1);
    }
    
    TreeNode *sub(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            auto ret = new TreeNode(A[left]);
            return ret;
        }
        int index = left;
        for (int i = left+1; i <= right; ++i) {
            if (A[i] > A[index]) {
                index = i;
            }
        }
        auto ret = new TreeNode(A[index]);
        ret->left = sub(A, left, index-1);
        ret->right = sub(A, index+1, right);
        return ret;
    }
};
