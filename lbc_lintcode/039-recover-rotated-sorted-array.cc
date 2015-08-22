/*
题目：26 % 恢复旋转排序数组 容易

题目大意：
给定一个旋转过的排序数组，恢复之。
要求时间复杂度n， 空间复杂度1

解题思路：
翻转url类似

遇到的问题：
竟然没有考虑其中有重复元素的情况。
真是罪过呀。
*/
class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int index = 0;
        while (index < nums.size()-1 && nums[index] <= nums[index+1]) index++;
        reverse(nums, 0, index);
        reverse(nums, index+1, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
    
    void reverse(vector<int> &nums, int left, int right) {
        if (right-left <= 0) return;
        for (int i = left; i < left+(right-left+1)/2; ++i) {
            swap(nums[i], nums[right+left-i]);
        }
    }
};
