/*
题目：27 % 上一个排列 中等

题目大意：
给定一个数组，其中存在重复元素。求该数组的上一个排列？

解题思路：
跟下一个排列类似

遇到的问题：
还是各种顺序问题。
*/
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        vector<int> ans(nums.begin(), nums.end());
        if (nums.size() < 2) return ans;
        int index = nums.size()-1;
        while (index > 0 && nums[index] >= nums[index-1]) index--;
        if (index == 0) {
            for (int i = 0; i < ans.size()/2; ++i) {
                swap(ans[i], ans[ans.size()-1-i]);
            }
            return ans;
        }
        int first = nums.size()-1;
        while (nums[first] >= nums[index-1]) first--;
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
