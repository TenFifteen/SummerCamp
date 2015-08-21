/*
题目：25 % 数组划分 中等

题目大意：
将数组按照k为基准，小的在前，大于等于的在后

解题思路：
两指针

遇到的问题：
与快速排序差不多，只不过快速排序比这个还要复杂一些。
*/
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[left] < k)left++;
            while (left < right && nums[right] >= k)right--;
            swap(nums[left], nums[right]);
        }
        if (nums[right] >= k) return right;
        else return right + 1;
    }
};
