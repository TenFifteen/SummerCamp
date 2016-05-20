/*
题目大意：
给定一个数组，求最大的接水的容量。

解题思路：
见代码。

遇到的问题：
没有
*/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        if (heights.size() < 3) return 0;
        
        int n = heights.size();
        vector<int> partial_max(n);
        partial_max[0] = heights[0];
        for (int i = 1; i < n; ++i) {
            partial_max[i] = max(partial_max[i-1], heights[i]);
        }
        
        int ans = 0, right_max = heights.back();
        for (int i = n-1; i > 0; --i) {
            int bar = min(partial_max[i-1], right_max);
            ans += max(0, bar - heights[i]);
            right_max = max(right_max, heights[i]);
        }
        
        return ans;
    }
};
