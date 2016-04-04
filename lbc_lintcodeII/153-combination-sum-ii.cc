/*
题目大意：
给定一个数组，求其中所有的和为target的组合。每个数字只能用一次。

解题思路：
见代码。

遇到的问题：
没有太大问题，不过一开始忘记了去重了。
*/
class Solution {
    void dfs(vector<vector<int>> &ans, vector<int> &cur, vector<int> &num, int index, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        if (index >= num.size()) return;
        
        for (int i = index; i < num.size(); ++i) {
            if (i != index && num[i] == num[i-1]) continue;
            cur.push_back(num[i]);
            dfs(ans, cur, num, i+1, sum+num[i], target);
            cur.pop_back();
        }
    }
    
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, num, 0, 0, target);
        return ans;
    }
};