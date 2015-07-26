/*
题目大意：
给一个数组，求出所有的排列。数字有重复。

解题思路：
用树的层次来防止重复。

遇到的问题：
本来46题就已经处理了重复了。
结果发现其实是有问题的，去掉了之前的处理方式，换成了：
while(i+1 < nums.size() && nums[i+1] == nums[i])i++;
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        vector<int> cur;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        sub(ans, nums, cur, flag);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &nums, vector<int> &cur, vector<bool> &flag){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(flag[i])continue;
            //if(i != 0 && nums[i] == nums[i-1])continue;
            cur.push_back(nums[i]);
            flag[i] = true;
            sub(ans, nums, cur, flag);
            cur.pop_back();
            flag[i] = false;
            while(i+1 < nums.size() && nums[i+1] == nums[i])i++;
        }
    }
};