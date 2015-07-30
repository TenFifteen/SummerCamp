/*
题目大意：
给定一个三角，求出从头到底的最小的路径。

解题思路：
动态规划。

遇到的问题：
一些边界问题。
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> ans(triangle.size()), last(triangle.size());
        if(triangle.size() == 0)return 0;
        last[0] = triangle[0][0];
        ans[0] = last[0];
        for(int i = 1; i < triangle.size(); ++i){
            ans[0] = last[0] + triangle[i][0];
            for(int j = 1; j < i; ++j){
                ans[j] = min(last[j], last[j-1]) + triangle[i][j];
            }
            ans[i] = last[i-1] + triangle[i][i];
            last = ans;
        }
        int ret = ans[0];
        for(int i = 1; i < ans.size(); ++i){
            if(ans[i] < ret){
                ret = ans[i];
            }
        }
        return ret;
    }
};