/*
题目：32 % 接雨水 中等

题目大意；
给定一个数组，表示一个单位的高度。问这个数组最多能接多少水

解题思路：
找到两遍的边界

遇到的问题：
没有问题。
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
        vector<int> left(heights.size()), right(heights.size());
        for (int i = 1; i < heights.size(); ++i) {
            left[i] = max(left[i-1], heights[i-1]);
        }
        for (int i = heights.size()-2; i >= 0; --i) {
            right[i] = max(right[i+1], heights[i+1]);
        }
        int ret = 0;
        for (int i = 1; i < heights.size()-1; ++i) {
            int side = min(left[i], right[i]);
            if (side > heights[i]) {
                ret += side - heights[i];
            }
        }
        return ret;
    }
};
