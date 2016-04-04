/*
题目大意：
给定一个数组，表示n个柱子。找到两个柱子，他们可以装下最多的水。

解题思路： 
卡尺法。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        if (heights.size() < 2) return 0;
        int left = 0, right = heights.size()-1, ans = 0;
        while (left < right) {
            ans = max(ans, min(heights[left], heights[right])*(right-left));
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return ans;
    }
};