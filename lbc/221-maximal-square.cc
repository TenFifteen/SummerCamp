/*
题目大意：
给定一个二维的01矩阵，求出其中全部为1的正方形的面积是多少？

解题思路：
动态规划。

遇到的问题：
一开始求成了最大的矩形了。
而且，将动态转移方程的下标写错了。
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return 0;
        vector<vector<pair<int,int>>> line(matrix.size(), vector<pair<int,int>>(matrix[0].size(), make_pair(0,0)));
        vector<vector<pair<int,int>>> dp(matrix.size(), vector<pair<int,int>>(matrix[0].size(), make_pair(0,0)));
        if(matrix[0][0] == '1'){
            line[0][0] = make_pair(1,1);
            dp[0][0] = line[0][0];
        }
        for(int i = 1; i < matrix.size(); ++i){
            if(matrix[i][0] == '1'){
                line[i][0].second = line[i-1][0].second + 1;
                line[i][0].first = 1;
                dp[i][0] = line[i][0];
            }
        }
        for(int i = 1; i < matrix[0].size(); ++i){
            if(matrix[0][i] == '1'){
                line[0][i].first = line[0][i-1].first + 1;
                line[0][i].second = 1;
                dp[0][i] = line[0][i];
            }
        }
        
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[i].size(); ++j){
                if(matrix[i][j] == '1'){
                    line[i][j].first = line[i][j-1].first+1;
                    line[i][j].second = line[i-1][j].second+1;
                    dp[i][j].first = min(dp[i-1][j-1].first+1,line[i][j].first);
                    dp[i][j].second = min(dp[i-1][j-1].second+1,line[i][j].second);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                int tmp = min(dp[i][j].first, dp[i][j].second);
                if(tmp * tmp > ret){
                    ret = tmp * tmp;
                }
            }
        }
        return ret;
    }
};