/*
题目大意：
给一个排序的数组旋转一下，然后恢复之。

解题思路：
找到拐点，然后三次翻转。

遇到的问题：
偷了个懒，找拐点没有用二分。
*/
class Solution {
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    
    int findBreak(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) return i;
        }
        return nums.size();
    }
    
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0) return;
        
        int mid = findBreak(nums);
        if (mid == nums.size()) return;
        
        reverse(nums, 0, mid-1);
        reverse(nums, mid, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
};