/*
题目：39 % 爬楼梯 容易

题目大意：
给定一个梯子的阶梯数，一次可以走一个阶梯，也可以走两个阶梯。
问一共有多少种走法。

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n < 2) return n;
        int a = 1, b = 1;
        for (int i = 1; i < n; ++i) {
            auto tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};

