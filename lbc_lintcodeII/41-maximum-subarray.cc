/*
题目大意：
给定一个数组，求其最大的子数组和

解题思路：
动归

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        
        int ans = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            cur = max(cur+nums[i], nums[i]);
            ans = max(cur, ans);
        }
        return ans;
    }
};
