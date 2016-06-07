/**
 * Problem: You are given an integer array nums and you have to return a new counts array.
 *          The counts array has the property where counts[i] is the number of smaller
 *          elements to the right of nums[i].
 * Solve: insert each node to a BST from the end to the begin.
 *        Sum the count(left all nodes + duplicates) every time we turn right.
 * Tips: note the duplicates.
 *       The way to sum the left all nodes: when a node pass by now node add one.
 */
class TNode {
    public:
        TNode* left, *right;
        int val, cnt, leftSum;

        TNode(int v) {
            left = right = NULL;
            val = v;
            cnt = 1;
            leftSum = 0;
        }
};

class Solution {
    public:
        vector<int> countSmaller(vector<int>& nums) {
            int n = nums.size();

            vector<int> ans(n);
            TNode *root = NULL;
            for (int i = n-1; i >= 0; --i) {
                root = insert(root, ans, i, nums[i], 0);
            }

            return ans;
        }

        TNode *insert(TNode *root, vector<int> &ans, int &index, int &val, int cnt) {
            if (root == NULL) {
                ans[index] = cnt;
                return new TNode(val);
            }

            if (val < root->val) {
                // very important!! count the all nodes in left branch.
                root->leftSum++;
                root->left = insert(root->left, ans, index, val, cnt);
            } else if (val > root->val) {
                root->right = insert(root->right, ans, index, val, cnt+root->cnt+root->leftSum);
            } else {
                root->cnt++;
                ans[index] = cnt + root->leftSum;
            }

            return root;
        }
};
