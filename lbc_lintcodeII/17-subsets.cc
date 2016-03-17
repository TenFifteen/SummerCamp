/*
题目大意：
给定一个数组，其中数字无重复，问所有的子集是什么？

解题思路：
用了迭代式的

遇到的问题：
第一次用迭代式，效果还不错。
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
    	ans.push_back(vector<int>());
    	
    	for (auto n : nums) {
    	    int len = ans.size();
    	    for (int i = 0; i < len; ++i) {
    	        vector<int> cur = ans[i];
    	        cur.push_back(n);
    	        ans.push_back(cur);
    	    }
    	}
    	
    	return ans;
    }
};