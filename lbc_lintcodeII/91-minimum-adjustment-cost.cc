/*
题目大意：
给定一个数组，将其调整到相邻元素的差值不得大于target，
问最小的调整代价是多少？

解题思路：
动归。复杂度是n*k*100

遇到的问题：
不知道还有没有更好的解？
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        if (A.size() < 2) return 0;
        
        vector<vector<int>> dp(A.size()+1, vector<int>(101, INT_MAX>>1));
        for (int i = 0; i <= 100; ++i) dp[0][i] = 0;
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 0; j <= 100; ++j) {
                for (int k = max(0, j-target); k <= min(100, j+target); ++k) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(A[i-1]-j));
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i <= 100; ++i) {
            ans = min(ans, dp[A.size()][i]);
        }
        return ans;
    }
    /*
    TreeNode *find(TreeNode *root, int val) {
        if (root == NULL) return NULL;
        
        if (root->val <= val) return find(root->right, val);
        
        TreeNode *ret = find(root->left, val);
        
        if (ret == NULL) return root;
        else return ret;
    }
    */
};