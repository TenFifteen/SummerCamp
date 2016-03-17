/*
题目大意：
给定一个数组，将其按照kpartition

解题思路：
见代码

遇到的问题：
没有。
*/
class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0) return 0;
        
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[left] < k) left++;
            while (left < right && nums[right] >= k) right--;
            swap(nums[left], nums[right]);
        }
        
        if (nums[left] >= k) return left;
        else return left+1;
    }
};