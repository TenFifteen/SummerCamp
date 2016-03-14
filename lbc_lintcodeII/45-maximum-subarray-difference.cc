/*
题目大意：
给定一个数组，求两个没有重叠的子数组的差的绝对值的最大值

解题思路：
求一次最小，求一次最大即可

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) return 0;
        
        //left big, right small
        vector<int> Max(nums);
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (sum > 0) sum += nums[i];
            else sum = nums[i];
            Max[i] = max(Max[i-1], sum);
        }
        
        sum = nums.back();
        int Min = sum, ans = abs(Max[nums.size()-2]-sum);
        for (int i = nums.size()-2; i > 0; --i) {
            if (sum < 0) sum += nums[i];
            else sum = nums[i];
            Min = min(sum, Min);
            ans = max(ans, abs(Max[i-1]-sum));
        }
        
        //left small, right big
        Max.back() = nums.back(), sum = nums.back();
        for (int i = nums.size()-2; i >= 0; --i) {
            if (sum > 0) sum += nums[i];
            else sum = nums[i];
            Max[i] = max(Max[i+1], sum);
        }
        
        sum = nums.front(), Min = sum;
        ans = max(ans, abs(Max[1]-sum));
        for (int i = 1; i < nums.size()-1; ++i) {
            if (sum < 0) sum += nums[i];
            else sum = nums[i];
            Min = min(Min, sum);
            ans = max(ans, abs(Max[i+1]-Min));
        }
        
        return ans;
    }
};
