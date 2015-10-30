/*
题目：27 % 颠倒整数 容易

题目大意：
给定一个整数，将其翻转过来，要注意负数和溢出等情况。

解题思路：
见代码

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long long nn = n;
        bool neg = false;
        if (nn < 0) {
            neg = true;
            nn = -nn;
        }
        int ans = 0;
        while (nn) {
            int old = ans;
            ans *= 10;
            ans += nn%10;
            nn /= 10;
            if (ans/10 != old) {
                return 0;
            }
        }
        if (neg) {
            return -ans;
        } else {
            return ans;
        }
    }
};
