/*
题目大意：
给定一个直方图，求其中最大的矩形面积

解题思路：
用一个栈存放当前单调递增的序列，当一个数据出栈的时候，计算该高度的最大的矩形面积

遇到的问题：
这个题目很容易忘掉。。。
*/
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        stack<pair<int, int>> s;
        s.push(make_pair(-1, -1));
        
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (s.top().second >= height[i]) {
                pair<int, int> cur = s.top(); s.pop();
                int now = (i-s.top().first-1)*cur.second;
                ans = max(ans, now);
            }
            s.push(make_pair(i, height[i]));
        }
        
        while (s.size() > 1) {
            pair<int, int> cur = s.top(); s.pop();
            int now = (height.size()-s.top().first-1)*cur.second;
            ans = max(ans, now);
        }
        
        return ans;
    }
};
