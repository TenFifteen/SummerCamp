/*
题目大意：
给定一个正整数数组，一个k值，一个target值。问有多少种k个数的组合可以使得其和为target

解题思路：
三维动归

遇到的问题：
一开始把相加搞成了取max了。
另外就是一开始把内层两个循环的方向搞反了。
所以今天面试一定要极力避免这种低级错误出现。
*/
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n = A.size();
        
        vector<vector<int>> dp(k+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                for (int m = target; m >= 1; --m) {
                    if (m >= A[i]) dp[j][m] += dp[j-1][m-A[i]];
                }
            }
        }
        
        return dp[k][target];
    }
};