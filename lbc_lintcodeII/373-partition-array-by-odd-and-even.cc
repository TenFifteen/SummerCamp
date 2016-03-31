/*
题目大意：
给定一个数组，将其中的奇数放到数组的左边，偶数放到数组的右边。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return;
        
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[left] & 0x1) left++;
            while (left < right && !(nums[right] & 0x1)) right--;
            swap(nums[left], nums[right]);
        }
    }
};