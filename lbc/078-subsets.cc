/*
题目大意：
给一个数组，找出所有的子集合。

解题思路：
回溯。

遇到的问题：
竟然忘了排序。
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        sub(ans, nums, 0, cur);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &nums, int index, vector<int> &cur){
        if(index == nums.size()){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        sub(ans, nums, index+1, cur);
        cur.pop_back();
        sub(ans, nums, index+1, cur);
    }
};