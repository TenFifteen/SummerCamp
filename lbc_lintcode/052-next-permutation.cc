/*
题目：23 % 下一个排列 中等

题目大意：
给出一个带有重复数字的数组，求出该数组的下一个排列

解题思路：
按照排列的定义进行求解

遇到的问题：
这种题目一定要想清楚了才能动手写，很容易出错的。
*/
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        vector<int> ans(nums.begin(), nums.end());
        if (nums.size() < 2) return ans;
        int index = nums.size()-1;
        while (index > 0 && nums[index] <= nums[index-1]) index--;
        if (index == 0) {
            for (int i = 0; i < nums.size()/2; ++i) {
                swap(ans[i], ans[nums.size()-1-i]);
            }
            return ans;
        }
        int first = nums.size()-1;
        while (nums[first] <= nums[index-1]) first--;
        int ret = index-1;
        ans[ret++] = nums[first];
        for (int i = nums.size()-1; i > first; --i) {
            ans[ret++] = nums[i];
        }
        ans[ret++] = nums[index-1];
        for (int i = first-1; i >= index; --i) {
            ans[ret++] = nums[i];
        }
        return ans;
    }
};
