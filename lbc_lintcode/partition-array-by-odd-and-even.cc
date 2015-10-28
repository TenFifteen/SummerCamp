/*
题目：37 % 奇偶分割数组 容易

题目大意：
给定一个数组，将其按照奇数偶数的顺序进行排序。

解题思路：
两个指针

遇到的问题：
没有问题。
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
            while (left < right && nums[left]%2 == 1) left++;
            while (left < right && nums[right]%2 == 0) right--;
            swap(nums[left++], nums[right--]);
        }
    }
};
