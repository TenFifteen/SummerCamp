/*
题目大意：
给定一个数组，求其最长的上升子序列。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
    int binarySearch(vector<int> &lis, int val) {
        int left = 0, right = lis.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (lis[mid] > val) right = mid;
            else left = mid+1;
        }
        
        if (lis[left] > val) return left;
        else return left+1;
    }
    
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) return nums.size();
        
        vector<int> lis;
        lis.push_back(nums.front());
        
        for (int i = 1; i < nums.size(); ++i) {
            int index = binarySearch(lis, nums[i]);
            if (index == lis.size()) lis.push_back(nums[i]);
            else lis[index] = nums[i];
        }
        
        return lis.size();
    }
};
