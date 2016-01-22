/*
题目大意：
用k个1-9的数字组合其和来组成n，不可以重复。

解题思路：
搜索

遇到的问题：
一开始以为是可以重复的。

再次阅读：
感觉这样做基本没啥问题了。
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> now;
        sub(k, n, 1, ans, now);
        return ans;
    }
    
    void sub(int k, int n, int cur, vector<vector<int>> &ans, vector<int> &now){
        if(n == 0){
            if(k == 0)ans.push_back(now);
            return;
        }
        if(k*cur > n || k*9 < n || k <= 0)return;
        for(int i = cur; i <= 9; ++i){
            now.push_back(i);
            sub(k-1, n-i, i+1, ans, now);
            now.pop_back();
        }
    }
};