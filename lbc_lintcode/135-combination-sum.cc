/*
题目：27 % 数字组合 中等

题目大意：
给定一个数组，一个target，问所有的数组元素加和为target的组合有哪些。

解题思路：
搜索

遇到的问题：
虽然一次写对了。
但是还是对这个思路为啥可以去重不太明白。
*/
class Solution {
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
        sub(ans, cur, candidates, target, 0, 0);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &cur, vector<int> &candidates, int target, int sum, int index) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (i != index && candidates[i] == candidates[i-1])continue;
            sum += candidates[i];
            cur.push_back(candidates[i]);
            sub(ans, cur, candidates, target, sum, i);
            cur.pop_back();
            sum -= candidates[i];
        }
    }
};
