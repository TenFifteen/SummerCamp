/*
题目：32 % 排颜色 II 中等

题目大意：
给定一个数组，其中表示的是1-k的颜色。现在要求给该数组排序，要求不能使用额外的空间。

解题思路：
将其转化为两种颜色求解方法的递归形式，复杂度是nlogk

遇到的问题：
不知道是否有线性算法。
当然除了计数排序之外。

精彩解答：
的确是有人的解法比较巧妙啊。
就是利用colors本身来进行计数排序。
http://www.cnblogs.com/yuzhangcmu/p/4177326.html
*/
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        if (k < 2 || colors.size() < 2) return;
        sub(colors, 0, colors.size()-1, 1, k);
    }
    
    void sub(vector<int> &colors, int left, int right, int k1, int k2) {
        if (k1 >= k2 || left >= right) return;
        int k3 = k1 + (k2-k1+1)/2;
        int L = left, R = right;
        while (L < R) {
            while (L < R && colors[L] < k3) L++;
            while (L < R && colors[R] >= k3) R--;
            swap(colors[L], colors[R]);
        }
        if (colors[L] < k3) {
            sub(colors, left, L, k1, k3-1);
            sub(colors, L+1, right, k3, k2);
        } else {
            sub(colors, left, L-1, k1, k3-1);
            sub(colors, L, right, k3, k2);
        }
    }
};
