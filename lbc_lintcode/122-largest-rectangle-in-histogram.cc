/*
题目：24 % 直方图最大矩形覆盖 困难

题目大意：
给定一个直方图，每一个柱宽度是1.问其中最大的矩形的面积是多少

解题思路：
用一个比较巧妙的思路解决。
用一个栈来记录当前递增的序列，当一个数弹出时，可以知道，后面的元素肯定是比他小，最后边的边界就是
i-1;
前面的边界就是栈里的最上面的元素

遇到的问题：
这个东西还真是绕啊。
*/
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        stack<int> stk;
        if (height.size() == 0) return 0;
        stk.push(0);
        int ret = INT_MIN;
        for (int i = 1; i < height.size(); ++i) {
            if (stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i);
            } else {
                while (!stk.empty() && height[stk.top()] > height[i]) {
                    auto cur = stk.top();
                    stk.pop();
                    int rectangle = 0;
                    if (stk.empty()) {
                        rectangle = i * height[cur];
                    } else {
                        rectangle = (i - stk.top() - 1) * height[cur];
                    }
                    if (rectangle > ret) {
                        ret = rectangle;
                    }
                }
                i--;
            }
        }
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            int rectangle = 0;
            if (stk.empty()) {
                rectangle = height.size() * height[cur];
            } else {
                rectangle = (height.size()-1-stk.top()) * height[cur];
            }
            if (rectangle > ret) {
                ret = rectangle;
            }
        }
        return ret;
    }
};

