/*
题目大意：
给定一个正数组成的数组，求其最小的子数组的和大于等于s

解题思路：
卡尺法

遇到的问题：
首先是while条件一开始搞错了。
然后是返回值忘记了判断了。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        if (nums.size() == 0) return -1;
        
        int left = 0, right = 0, sum = 0, ans = INT_MAX;
        while (right < nums.size()) {
            while (right < nums.size() && sum < s) {
                sum += nums[right];
                right++;
            }
        
            while (sum >= s) {
                ans = min(ans, right-left);
                sum -= nums[left++];
            }
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};