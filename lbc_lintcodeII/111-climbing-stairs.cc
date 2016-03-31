/*
题目大意：
上楼梯的方式。

解题思路：
动归。

遇到的问题：
n == 0的时候竟然返回1
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n < 2) return 1;
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};
