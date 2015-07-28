/*
题目大意：
给定一个二维矩阵，求从左上角到右下角的所有路径中，路径上的所有数字的和最小。

解题思路：
动态规划。

遇到的问题：
无问题。
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