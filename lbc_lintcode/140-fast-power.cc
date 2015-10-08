/*
题目:19 % 快速幂 中等

题目大意：
快速求幂

解题思路：
见代码

遇到的问题：
竟然一次通过。
*/
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (n == 0) return 1 % b;
        long long ans = a;
        vector<long long> buf(32);
        for (int i = 0; i < 32; ++i) {
            buf[i] = ans;
            ans = ans * ans % b;
        }
        ans = 1;
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) {
                ans *= buf[i];
                ans %= b;
                n -= (1 << i);
            }
            if (n == 0) break;
        }
        return ans;
    }
};
