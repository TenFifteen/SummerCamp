/*
题目：26 % 数字三角形 容易

题目大意：
给定一个三角形，求从上到下的所有路径中中，哪一条的路径和最小。

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if (triangle.size() == 0) return 0;
        vector<int> dp(triangle.size());
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            vector<int> next(triangle.size());
            next[0] = dp[0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size()-1; ++j) {
                next[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
            next[triangle[i].size()-1] = dp[triangle[i].size()-2] + triangle[i][i];
            dp.swap(next);
        }
        int ans = dp[0];
        for (auto a : dp) {
            if (a < ans) {
                ans = a;
            }
        }
        return ans;
    }
};

