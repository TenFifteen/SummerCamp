/*
题目：20 % k数和 困难

题目大意：
给定一个数组，每个数字都不相同。要求k个数加起来和为target的种类。

解题思路：
动态规划。

遇到的问题：
一开始感觉就是动归，但是实在是想不出二维的转移方程。
然后考虑了一下三维的，但是没有太大自信。
结果看了别人的解法，果然是三维的动归。
也就是说要对自己的结果有信息，另外就是高维动归并不可怕。
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
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(A.size()+1, vector<int>(target+1, 0)));
        for (int i = 0; i < A.size(); ++i) {
            if(A[i] <= target) {
                for (int j = i; j < A.size(); ++j) {
                    dp[1][j+1][A[i]] = 1;
                }
            }
        }
        for (int i = 2; i <= k; ++i) {
            for (int j = i; j <= A.size(); ++j) {
                for (int v = 1; v <= target; ++v) {
                    dp[i][j][v] = dp[i][j-1][v];
                    if (A[j-1] <= v) {
                        dp[i][j][v] += dp[i-1][j-1][v-A[j-1]];
                    }
                }
            }
        }
        return dp[k][A.size()][target];
    }
};
