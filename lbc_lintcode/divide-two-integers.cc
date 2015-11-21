/*
题目：15 % 两个整数相除 中等

题目大意：
不用除法，乘法，取模，来进行整数的除法运算。

解题思路：
用移位。将除数不断的向左移位，直到大于被除数。

遇到的问题：
一开始没想到，看了别人说的才知道的。
*/
class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return 2147483647;
        }
        bool neg = false;
        long long x = dividend;
        if (x < 0) {
            x = -x;
            neg = !neg;
        }
        long long y = divisor;
        if (y < 0) {
            y = -y;
            neg = !neg;
        }
        
        int ret = 0;
        while (x >= y) {
            int i = 0;
            while ((y << i) <= x) {
                i++;
            }
            i--;
            ret += (1 << i);
            x -= (y << i);
        }
        if (neg) {
            return -ret;
        } else {
            return ret;
        }
    }
};
