/*
题目大意：
给定一个数组，一个区间大小k。问没有k区间大小的子数组的最大值是多少？

解题思路：
单调队列。

遇到的问题：
中间搞错了一个边界值，使得区间变成了k+1
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        deque<int> q;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i) {
            while (q.size() > 0 && q.front() < i-k+1) q.pop_front();
            while (q.size() > 0 && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            
            if (i >= k-1) ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};
