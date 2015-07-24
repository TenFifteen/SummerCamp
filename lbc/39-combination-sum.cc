/*
题目大意：
给定一个数组，一个target，数字可以重复使用。找出所有不重复的组合，其和等于target。

解题思路：
用上了之前学到的按层访问的方式，进行深搜回溯

遇到的问题：
忘了排序。
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