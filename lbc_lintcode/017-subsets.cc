/*
题目：22 % 子集 中等

题目大意：
给定一个数组，求所有的组合

解题思路：
递归求解

遇到的问题：
一开始在递归的时候竟然在sub中写上了for循环，真是糊涂啊。
*/
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int>> ans;
    	if (nums.size() == 0) {
    	    ans.push_back(nums);
    	    return ans;
    	}
    	sort(nums.begin(), nums.end());
    	vector<int> cur;
    	sub(nums, ans, cur, 0);
    	return ans;
    }

    void sub(vector<int> &nums, vector<vector<int>> &ans, vector<int> &cur, int x) {
        if (x == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        sub(nums, ans, cur, x+1);
        cur.push_back(nums[x]);
        sub(nums, ans, cur, x+1);
        cur.pop_back();
    }
};
