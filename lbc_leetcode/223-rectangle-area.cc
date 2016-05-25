/*
题目大意：
给定两个平面矩形，求其总共的面积。可能会有重叠。

解题思路：
主要是如何计算重叠部分面积。
方法就是左下角的值选两个左下角中的大的；右上角的值取两个右上角的小的。

遇到的问题：
没有问题。

再次阅读：
感觉没啥问题。
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
/*
第二次做：
这次做的时候竟然想的跟第一次不一样了。。。。
想了一大堆东西计算中间重叠部分，但是总是有一些奇怪的测试用例。
比如一个包含一个，一个是一条线，或者一个点。或者交叠的部分是侧面部分包含进去。
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C-A) * (D-B), areaB = (G-E) * (H-F);
        
        int botX = max(A, E), botY = max(B, F);
        int topX = min(C, G), topY = min(D, H);
        
        int cross = 0;
        if (topX > botX && topY > botY) cross = (topX-botX) * (topY - botY);
        
        return areaA - cross + areaB;
    }
};