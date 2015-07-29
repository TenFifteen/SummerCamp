/*
题目大意：
给定楼梯的数目。每次爬一个或者两个。问一共有多少种爬法。

解题思路：
动态规划的最基本题目。

遇到的问题：
无问题，一次通过。
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)return n;
        int a = 1,b = 1;
        for(int i = 1; i < n; ++i){
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};