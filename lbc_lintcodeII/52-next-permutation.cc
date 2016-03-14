/*
题目大意：
给定一个排列，求下一个排列。

解题思路：
按照定义求解。

遇到的问题：
没有。
*/
class Solution {
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return nums;
        
        int i = nums.size()-1;
        while (i > 0 && nums[i] <= nums[i-1]) i--;
        
        if (i == 0) {
            reverse(nums, 0, nums.size()-1);
            return nums;
        }
        
        int j = i;
        while (j < nums.size() && nums[j] > nums[i-1]) j++;
        
        swap(nums[i-1], nums[j-1]);
        reverse(nums, i, nums.size()-1);
        return nums;
    }
};