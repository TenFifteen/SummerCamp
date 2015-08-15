/*
题目：尾部的零 容易

题目大意：
给定一个n，求n！的尾部的0有多少个

解题思路：
直接算

遇到的问题：
老问题，没有问题
*/
class Solution {
public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long ans = 0;
        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};

