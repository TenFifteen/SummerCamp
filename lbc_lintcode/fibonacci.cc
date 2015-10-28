/*
题目：30 % 斐波纳契数列 入门

题目大意：
求第n个斐波那契数列的元素。

解题思路：
见代码

遇到的问题：
没有问题。
*/
class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n == 1) return 0;
        if (n == 2) return 1;
        int a1 = 0, a2 = 1;
        for (int i = 0; i < n-2; ++i) {
            auto tmp = a1+a2;
            a1 = a2;
            a2 = tmp;
        }
        return a2;
    }
};

