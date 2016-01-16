/*
题目大意：
给一个二维矩阵，问从左上角走到右下角，一共有多少种走法。

解题思路：
动态规划。

遇到的问题：
一次通过。

再次阅读:
题目很简单，就是一个最简单的动归。
然后看了一眼之前写的代码。这是唯一一个我觉得比DISCUSS中的代码好的。空间也已经优化。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(m,1);
        for(int i = 0; i < n-1; ++i){
            for(int j = 1; j < m; ++j){
                ans[j] += ans[j-1];
            }
        }
        return ans[m-1];
    }
};