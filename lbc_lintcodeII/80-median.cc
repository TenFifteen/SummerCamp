/*
题目大意：
给定无序数组，求中位数。

解题思路：
二分。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int k = (nums.size()-1)/2;
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int L = left, R = right, mid = nums[L];
            while (L < R) {
                while (L < R && nums[R] > mid) R--;
                nums[L] = nums[R];
                while (L < R && nums[L] <= mid) L++;
                nums[R] = nums[L];
            }
            nums[L] = mid;
            
            if (L == k) return nums[L];
            if (L > k) right = L-1;
            else left = L+1;
        }
        return nums[left];
    }
};
