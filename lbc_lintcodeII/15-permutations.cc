/*
题目大意：
给定一个数组，没有重复数据。求所有的排列。

解题思路：
迭代式的计算

遇到的问题：
没有。
*/
class Solution {
    void reverse(vector<int> &v, int left, int right) {
        while (left < right) {
            swap(v[left++], v[right--]);
        }
    }
    
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        
        while (true) {
            int peak = nums.size()-1;
            while (peak > 0 && nums[peak] < nums[peak-1]) peak--;
            
            if (peak == 0) break;
            
            int index = nums.size()-1;
            while (nums[index] < nums[peak-1]) index--;
            
            swap(nums[peak-1], nums[index]);
            reverse(nums, peak, nums.size()-1);
            ans.push_back(nums);
        }
        
        return ans;
    }
};
