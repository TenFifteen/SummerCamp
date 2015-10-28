/*
题目：33 % 下一个排列 中等

题目大意：
给定一个数组，求下一个排列的表示。

解题思路：
按照排列的定义求解，见代码。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return;
        if (isInorder(nums)) {
            reverse(nums, 0, nums.size()-1);
            return;
        }
        
        int index = nums.size()-2;
        while (nums[index] >= nums[index+1]) {
            index--;
        }
        int bigger = nums.size()-1;
        while (nums[bigger] <= nums[index]) {
            bigger--;
        }
        swap(nums[index], nums[bigger]);
        reverse(nums, index+1, nums.size()-1);
    }
    
    bool isInorder(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                return false;
            }
        }
        return true;
    }
    
    void reverse(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        
        for (int i = left; i < left + (right-left+1)/2; ++i) {
            swap(nums[i], nums[right-i+left]);
        }
    }
};
