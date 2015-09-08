/*
题目：27 % 最小调整代价 中等

题目大意：
给定一个数组，调整每个数，将其邻居的差值最大不超过target。
问最下的调整代价是多少？

解题思路：
动态规划

遇到的问题：
感觉最近的题目动态规划有点多啊。
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        vector<vector<int>> dp(A.size(), vector<int>(101, INT_MAX));
        for (int i = A[0]; i <= 100; ++i) {
            dp[0][i] = i-A[0];
        }
        for (int i = A[0]; i >= 0; --i) {
            dp[0][i] = A[0]-i;
        }
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j <= 100; ++j) {
                int cur = dp[i-1][j];
                for (int k = max(0, j-target); k <= min(100, j+target); ++k) {
                    if (dp[i-1][k] < cur) {
                        cur = dp[i-1][k];
                    }
                }
                if (cur != INT_MAX) {
                    dp[i][j] = cur + abs(A[i]-j);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= 100; ++i) {
            if (dp[A.size()-1][i] < ans) {
                ans = dp[A.size()-1][i];
            }
        }
        return ans;
    }
};
