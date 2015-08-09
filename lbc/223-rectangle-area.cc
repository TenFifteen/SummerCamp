/*
题目大意：
给定两个平面矩形，求其总共的面积。可能会有重叠。

解题思路：
主要是如何计算重叠部分面积。
方法就是左下角的值选两个左下角中的大的；右上角的值取两个右上角的小的。

遇到的问题：
没有问题。
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C-A) * (D-B);
        int areaB = (G-E) * (H-F);
        int bot_x = max(A,E);
        int bot_y = max(B,F);
        int top_x = min(C,G);
        int top_y = min(D,H);
        int cross = 0;
        if(bot_x < top_x && bot_y < top_y){
            cross = (top_x-bot_x) * (top_y-bot_y);
        }
        return areaA + areaB - cross;
    }
};