#include <iostream>

using namespace std;

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
/**
 * Problem: Given a binary tree, determine if it is height-balanced.
 * Solve: Use a sub method to get the depth, by the way, determine if
 *        it is height balanced.
 * Tips: use a global variable to hold the answer and when found, stop
 *       recursive.
 */
class Solution {
    private:
        bool balanced = true;

    public:
        int solve(TreeNode *root) {
            if (!balanced) return 0;
            if (root == NULL) return 0;

            int left = solve(root->left);
            int right = solve(root->right);

            if (abs(left - right) > 1) {
                balanced = false;
            }
            return max(left, right) + 1;
        }
        /**
         * @param root: The root of binary tree.
         * @return: True if this Binary tree is Balanced, or false.
         */
        bool isBalanced(TreeNode *root) {
            // write your code here
            balanced = true;
            solve(root);
            return balanced;
        }
};
int main()
{

}
