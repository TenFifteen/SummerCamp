/*
题目大意：
求一个数组的所有排列。有重复元素。

解题思路：
用的迭代式

遇到的问题：
一开始竟然突然不知道迭代式怎么写了。还是查了一下才想起来的。
哎，这不是最开始就知道的么。
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
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        
        while (true) {
            int peak = nums.size()-1;
            while (peak > 0 && nums[peak] <= nums[peak-1]) peak--;
            
            if (peak == 0) break;
            
            int index = nums.size()-1;
            while (nums[index] <= nums[peak-1]) index--;
            
            swap(nums[peak-1], nums[index]);
            reverse(nums, peak, nums.size()-1);
            ans.push_back(nums);
        }
        
        return ans;
    }
};