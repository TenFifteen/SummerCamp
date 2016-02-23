#incldue <iostream>

using namespace std;

/**
 * Problem: Given a binary tree, find its maximum depth.
 * Solve: recursive.
 * Tips: no
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
int main()
{

}
