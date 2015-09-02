/*
题目：19 % 三数之和 中等

题目大意：
给定一个数组，元素有重复，找出所有不重复的三元组，三者之和为0

解题思路：
固定第一个数，后面的两个数的和就是第一个数的相反数，然后就用两个元素和的方法寻找就行
时间复杂度是n*n。

遇到的问题：
一开始竟然没有想到，这个也算是老题了，还是不能好好的做出来。。。
*/
class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int cur = nums[left] + nums[right] + nums[i];
                if (cur == 0) {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    ans.push_back(tmp);
                    while (left < right && nums[left+1] == nums[left]) ++left;
                    while (left < right && nums[right-1] == nums[right]) --right;
                    left++;
                    right--;
                } else if (cur > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};

