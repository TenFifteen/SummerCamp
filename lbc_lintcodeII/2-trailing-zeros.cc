/*
题目大意：
给定一个n，求n的阶乘的结果中末尾的0的个数

解题思路：
计算其中所有5的因子的个数

遇到的问题：
没有。
*/
class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
