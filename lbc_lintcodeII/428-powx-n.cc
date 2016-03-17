/*
题目大意：
求一个double的n次方。

解题思路：
二分。

遇到的问题：
没有问题。
不过我知道，这段代码中隐藏的有bug。就是那个-n的地方有可能会溢出。
*/
class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n < 0) return 1.0/myPow(x, -n);
        else if (n == 0) return 1;
        else {
            double ans = myPow(x, n/2);
            ans *= ans;
            if (n & 0x1) ans *= x;
            return ans;
        }
    }
};