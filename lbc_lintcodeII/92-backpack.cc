/*
题目大意：
给定n个物品，每个都有大小。然后给一个背包，大小为m
问背包里可以装东西的最大体积是多大？

解题思路：
简单动归。

遇到的问题；
没有。
*/
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.size() == 0 || m <= 0) return 0;
        
        vector<int> dp(m+1, 0);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = m; j >= 0; --j) {
                if (A[i] <= j) dp[j] = max(dp[j], dp[j-A[i]] + A[i]);
            }
        }
        
        return dp[m];
    }
};