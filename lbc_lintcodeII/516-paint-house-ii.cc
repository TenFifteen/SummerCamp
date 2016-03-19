/*
题目大意：
给定n个房子，和对应的k种颜色的价格。相邻房子不能涂相同的颜色，问最小的成本是多少？

解题思路：
动归。但是用了特殊的优化方式把时间复杂度降到了nk而不是nkk

遇到的问题：
这道题我只能看到nkk的思路，而且感觉已经非常不错了。
但是在网上找了一下，结果还真有这么神奇的解法啊。学习了。
*/
class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        
        vector<int> dp(costs[0]);
        int min1 = INT_MAX, min2 = INT_MAX;
        for (auto x : dp) {
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }
        
        for (int i = 1; i < n; ++i) {
            int old_min1 = min1;
            int old_min2 = min2;
            
            min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < k; ++j) {
                if (dp[j] != old_min1 || old_min1 == old_min2) {
                    dp[j] = old_min1 + costs[i][j];
                } else {
                    dp[j] = old_min2 + costs[i][j];
                }
                
                if (dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }
        }
        
        return min1;
    }
};