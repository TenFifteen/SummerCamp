/*
题目大意：
给定一个数组，求其中所有和为sum的组合，每个数字可以使用多次。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<vector<int>> &ans, vector<int> &cur, vector<int> &candidates, int index, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (index >= candidates.size()) return;
        
        cur.push_back(candidates[index]);
        dfs(ans, cur, candidates, index, sum+candidates[index], target);
        cur.pop_back();
        dfs(ans, cur, candidates, index+1, sum, target);
    }
    
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, candidates, 0, 0, target);
        return ans;
    }
};