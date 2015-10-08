/*
题目：22 % 中位数 容易

题目大意：
给定一个乱序的数组，求其中位数，复杂度为n

解题思路：
只能利用快排思想进行查找第k大的数了。

遇到的问题：
没有问题。
竟然一次做对，太感动了。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        return findK(nums, 0, nums.size()-1, (nums.size()+1)/2);
    }
    
    int findK(vector<int> &nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int mid = nums[left];
        int L = left, R = right;
        while (L < R) {
            while (L < R && nums[R] >= mid) R--;
            swap(nums[R], nums[L]);
            while (L < R && nums[L] <= mid) L++;
            swap(nums[L], nums[R]);
        }
        nums[L] = mid;
        if (L == k-1) return nums[L];
        if (L < k-1) return findK(nums, L+1, right, k);
        else return findK(nums, left, L-1, k);
    }
};

