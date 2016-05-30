/*
题目大意：
给定一个有重复数字的排列，找到下一个排列。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
    bool isSorted(const vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) return false;
        }
        return true;
    }
    
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return;
        if (isSorted(nums)) {
            reverse(nums, 0, nums.size()-1);
            return; // forget at first
        }
        
        int index = nums.size()-2;
        while (nums[index] >= nums[index+1]) index--;
        
        int firstLargerThanIndex = nums.size()-1;
        while (nums[firstLargerThanIndex] <= nums[index]) firstLargerThanIndex--;
        
        swap(nums[firstLargerThanIndex], nums[index]);
        reverse(nums, index+1, nums.size()-1);
    }
};
