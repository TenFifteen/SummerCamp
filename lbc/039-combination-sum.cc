/*
题目大意：
给定一个数组，一个target，数字可以重复使用。找出所有不重复的组合，其和等于target。

解题思路：
用上了之前学到的按层访问的方式，进行深搜回溯

遇到的问题：
忘了排序。

再次阅读：
竟然一开始都没有想清楚之前的做法。
现在是看明白了，其实可以简单理解，就是当前位置依次放0-n-1这些数字的时候的所有的情况。
这样子的话，如果数字有重复的，可以直接跳过去不用处理就行了。
DISCUSS中不错的解法差不多也是这样子。
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> choose;
        sort(candidates.begin(), candidates.end());
        sub(ans, candidates, choose, target, 0, 0);
        return ans;
    }
    void sub(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &choose, int target, int sum, int cur){
        if(sum == target){
            ans.push_back(choose);
            return;
        }
        if(sum > target)return;
        
        for(int i = cur; i < candidates.size(); ++i){
            sum += candidates[i];
            choose.push_back(candidates[i]);
            sub(ans, candidates, choose, target, sum, i);
            sum -= candidates[i];
            choose.pop_back();
        }
    }
};