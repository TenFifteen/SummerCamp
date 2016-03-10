/*
题目大意：
给定一个数组，问其最大的子数组的乘积是多少？

解题思路：
动归

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        
        int ans = nums[0], Max = nums[0], Min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int newMax = max(Max*nums[i], Min*nums[i]);
            newMax = max(newMax, nums[i]);
            int newMin = min(Max*nums[i], Min*nums[i]);
            newMin = min(newMin, nums[i]);
            
            Max = newMax;
            Min = newMin;
            ans = max(Max, ans);
        }
        
        return ans;
    }
};