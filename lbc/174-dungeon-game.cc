/*
题目大意：
给定一个二维的board，然后需要从左上角到右下角去。
然后需要找到最初的一个体力值，使得某条路径上的所有点都是非负的。

解题思路：
动归+二分

遇到的问题：
原来看到这个题目的时候，感觉好像好难好难的，没敢做。
这次大体看了一下，感觉这个思路其实是可以做的。
然后竟然真的做出来了。
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int old = dungeon[0][0];
        long long left = INT_MIN, right = INT_MAX;
        int ret = INT_MAX;
        while(left <= right){
            long long mid = left + (right-left+1)/2;
            dungeon[0][0] = mid;
            if(sub(dungeon)){
                if(mid < ret){
                    ret = mid;
                }
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        ret -= old;
        if(ret <= 0)ret = 1;
        return ret;
    }
    
    bool sub(vector<vector<int>> &dungeon){
        vector<vector<long long>> dp(dungeon.size(), vector<long long>(dungeon[0].size()));
        dp[0][0] = dungeon[0][0];
        if(dp[0][0] <= 0)return false;
        for(int i = 1; i < dp.size(); ++i){
            if(dp[i-1][0] <= 0)dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0] + dungeon[i][0];
        }
        for(int i = 1; i < dp[0].size(); ++i){
            if(dp[0][i-1] <= 0)dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1] + dungeon[0][i];
        }
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 1; j < dp[0].size(); ++j){
                if(dp[i-1][j] <= 0 && dp[i][j-1] <= 0)dp[i][j] = 0;
                else if(dp[i-1][j] <= 0)dp[i][j] = dp[i][j-1] + dungeon[i][j];
                else if(dp[i][j-1] <= 0)dp[i][j] = dp[i-1][j] + dungeon[i][j];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dungeon[i][j];
            }
        }
        return dp[dp.size()-1][dp[0].size()-1] > 0;
    }
};