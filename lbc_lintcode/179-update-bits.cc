/*
题目：19 % 更新二进制位 中等

题目大意：
给定一个n和m。让将n的第i到j位设置成m

解题思路：
见代码

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        for (int x = i; x <= j; ++x) {
            if (n & (1 << x)) {
                n -= (1 << x);
            }
        }
        return n + (m << i);
    }
};
