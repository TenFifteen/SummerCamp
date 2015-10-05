/*
题目：25 % 滑动窗口的最大值 困难

题目大意：
给定一个数组，问窗口k大小的最大值是多少。

解题思路：
用一个multiset就可以解决。

遇到的问题：
竟然还需要处理边界问题。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0 || nums.size() < k) {
            vector<int> ans;
            return ans;
        }
        vector<int> ans(nums.size()+1-k);
        multiset<int> ms;
        for (int i = 0; i < k-1; ++i) {
            ms.insert(nums[i]);
        }
        for (int i = k-1; i < nums.size(); ++i) {
            ms.insert(nums[i]);
            ans[i-k+1] = *ms.rbegin();
            ms.erase(ms.find(nums[i-k+1]));
        }
        return ans;
    }
};

