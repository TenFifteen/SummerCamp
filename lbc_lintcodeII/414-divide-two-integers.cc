/*
题目大意：
不用乘除取余的方式实现除法。

解题思路：
利用移位的方式来做。

遇到的问题：
这次竟然有没有想起这个方法来，实在是不应该啊。
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
        if (divisor == 0 || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
        
        long long left = dividend, right = divisor;
        bool neg = false;
        if (left < 0) {
            neg = !neg;
            left = -left;
        }
        if (right < 0) {
            neg = !neg;
            right = -right;
        }
        
        long long ans = 0;
        while (left >= right) {
            int i = 0;
            while (left >= (right<<i)) i++;
            
            ans += 1 << (i-1);
            left -= right << (i-1);
        }
        
        if (neg) ans = -ans;
        return ans;
    }
};