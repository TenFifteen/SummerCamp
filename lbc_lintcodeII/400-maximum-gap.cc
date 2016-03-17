/*
题目大意：
给定一个无序数组，求在其有序的情况下，相邻元素的最大差值是多少？

解题思路：
桶排序

遇到的问题：
一开始还是没想出来，回去查的leetcode的代码。。。
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) return 0;
        
        int low = INT_MAX, high = 0;
        for (auto n : nums) {
            low = min(low, n);
            high = max(high, n);
        }
        
        long long total = high-low;
        total++;
        
        long long blockSize = total/nums.size();
        if (total % nums.size()) blockSize++;
        
        typedef pair<int, int> block;
        vector<block> blocks(nums.size(), make_pair(INT_MAX, INT_MIN));
        
        for (auto n : nums) {
            int blockID = (n-low)/blockSize;
            blocks[blockID].first = min(blocks[blockID].first, n);
            blocks[blockID].second = max(blocks[blockID].second, n);
        }
        
        block last;
        bool lastValid = false;
        int ans = 0;
        for (auto b : blocks) {
            if (b.second < b.first) continue;
            if (lastValid) {
                ans = max(b.first-last.second, ans);
                last = b;
            } else {
                lastValid = true;
                last = b;
            }
        }
        
        return ans;
    }
};