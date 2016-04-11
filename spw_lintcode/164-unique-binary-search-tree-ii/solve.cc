#include <iostream>
#include <vector>

/**
 * Problem: Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 * Solve: use left and right
 * Tips: new a root node when push to the answer vector. see comments below.
 */
using namespace std;
/**
 * Definition of TreeNode:
 */
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
    public:
        /**
         * @paramn n: An integer
         * @return: A list of root
         */
        vector<TreeNode *> generateTrees(int n) {
            return sub(1, n);
        }

        vector<TreeNode *> sub(int left, int right) {
            vector<TreeNode *> ans;
            if (left > right) {
                ans.push_back(NULL);
                return ans;
            }

            if (left == right) {
                ans.push_back(new TreeNode(left));
                return ans;
            }

            for (int i = left; i <= right; ++i) {
                vector<TreeNode *> leftTrees = sub(left, i-1);
                vector<TreeNode *> rightTrees = sub(i+1, right);

                for (int l = 0; l < leftTrees.size(); ++l) {
                    for (int r = 0; r < rightTrees.size(); ++r) {
                        // new a root every time.
                        TreeNode* root = new TreeNode(i);
                        root->left = leftTrees[l];
                        root->right = rightTrees[r];
                        ans.push_back(root);
                    }
                }
            }

            return ans;
        }
};

int main()
{
    Solution s;
    s.generateTrees(3);

    return 0;
}
