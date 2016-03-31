/*
题目大意：
给定一个三角形，问从上到下的所有路径中，sum最小是多少？

解题思路：
见代码。dp

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int n = triangle.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j = i-1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        
        int ans = INT_MAX;
        for (auto d : dp) {
            ans = min(ans, d);
        }
        
        return ans;
    }
};
