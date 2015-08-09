/*
题目大意：
给定一个数组，其中任意相邻的两个数字都不同。求出峰值元素的下标。峰值元素有很多，求其中任意一个就行。

解题思路：
二分查找。

遇到的问题：
一次通过。
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        if(nums[0] > nums[1])return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])return nums.size()-1;
        int left = 1, right = nums.size()-2;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])return mid;
            if(nums[mid] < nums[mid-1])right = mid-1;
            else left = mid+1;
        }
    }
};