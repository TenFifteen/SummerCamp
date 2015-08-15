/*
题目：统计数字 中等

题目大意：
给定一个n，一个k
k是个位数
计算[0,n]直接出现k的次数

解题思路：
一次计算每一位

遇到的问题：
也是之前遇到的一个问题，幸好使使劲做出来了
*/
class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10) {
            int left = n / i / 10;
            int right = n % i;
            int cur = n / i % 10;
            ans += left * i;
            if (cur == k) {
                ans += right + 1;
            } else if (cur > k) {
                ans += i;
            }
        }
        return ans;
    }
};
