/*
题目大意：
给定一个二维矩阵，求从左上角到右下角的所有路径中，路径上的所有数字的和最小。

解题思路：
动态规划。

遇到的问题：
无问题。

再次阅读：
又是一个简单的动归。但是这次的代码就没有进行优化，其实可以优化掉一维的空间复杂度的。
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i = 0; i < grid[0].size(); ++i){
            if(i == 0){
                ans[i] = grid[0][0];
            }else{
                ans[i] = ans[i-1]+grid[0][i];
            }
        }
        for(int i = 1; i < grid.size(); ++i){
            ans[0] += grid[i][0];
            for(int j = 1; j < grid[0].size(); ++j){
                ans[j] = min(ans[j], ans[j-1]) + grid[i][j];
            }
        }
        return ans[grid[0].size()-1];
    }
};
/*
第二次做：
比较简单的动归。不过一开始初始化条件搞错了。
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        for (int i = 0; i < m; ++i) {
            ans[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                ans[j] = min(ans[j-1], ans[j]) + grid[i][j];
            }
        }
        return ans[n-1];
    }
};
/*
 * some easy
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};
