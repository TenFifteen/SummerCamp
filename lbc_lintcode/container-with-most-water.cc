/*
题目：39 % 装最多水的容器 中等

题目大意：
给定一个数组，表示木板的高度，问最大的可以装下的水量是多少？

解题思路：
用的暴力。
但是看到别人用的都是两指针法（未理解）

遇到的问题：
本来就是想着试一下，感觉n*n的复杂度应该过不了，结果竟然过了。
但是看别人还是用的n的算法。都是两指针法，但是我还是不太理解那样为什么是对的。
贴一个链接：http://blog.csdn.net/wzy_1988/article/details/17248209
*/
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        if (heights.size() == 0) return 0;
        int ret = 0;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i+1; j < heights.size(); ++j) {
                int s = min(heights[i], heights[j]) * (j-i);
                if (s > ret) {
                    ret = s;
                }
            }
        }
        return ret;
    }
};
