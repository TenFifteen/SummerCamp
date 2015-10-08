/*
题目：33 % 背包问题 II 中等

题目大意：
01背包的经典问题。

解题思路：
动归

遇到的问题：
还没有优化空间复杂度
*/
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<vector<int>> dp(m+1, vector<int>(A.size()+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= A.size(); ++j) {
                dp[i][j] = dp[i][j-1];
                if (A[j-1] <= i) {
                    dp[i][j] = max(dp[i][j], dp[i-A[j-1]][j-1] + V[j-1]);
                }
            }
        }
        return dp[m][A.size()];
    }
};
