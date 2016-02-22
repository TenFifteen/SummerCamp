/*
题目大意：
与62题一样，但是矩阵中有障碍物。

解题思路：
动态规划。如果当前是障碍物，那么当前点的路是0；

遇到的问题：
无。

再次阅读：
跟上一个题基本一样，只不过需要注意一些不能走的路。
但是代码却比上一个题目差远了，其实只需要在上一个题目的基础上加上一句代码就可以了。

*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> tmp(obstacleGrid[0].size(), 0);
        vector<vector<int>> ans(obstacleGrid.size(), tmp);
        if(obstacleGrid[0][0] == 1)return 0;
        ans[0][0] = 1;
        for(int i = 1; i < obstacleGrid[0].size(); ++i){
            if(ans[0][i-1] == 1 && obstacleGrid[0][i] == 0){
                ans[0][i] = 1;
            }
        }
        for(int i = 1; i < obstacleGrid.size(); ++i){
            if(ans[i-1][0] == 1 && obstacleGrid[i][0] == 0){
                ans[i][0] = 1;
            }
            for(int j = 1; j < obstacleGrid[0].size(); ++j){
                if(obstacleGrid[i][j] == 1){
                    ans[i][j] = 0;
                }else{
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
                }
            }
        }
        return ans[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};