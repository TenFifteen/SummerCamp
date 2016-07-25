/*
题目大意：
给定楼梯的数目。每次爬一个或者两个。问一共有多少种爬法。

解题思路：
动态规划的最基本题目。

遇到的问题：
无问题，一次通过。

再次阅读:
太经典的动归了。
而且就是斐波那契数列
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
/*
第二次做：
太简单的动归了。
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;

        int a = 1, b = 2;
        for (int i = 2; i < n; ++i) {
            int next = a+b;
            a = b;
            b = next;
        }

        return b;
    }
};
/*
 * too easy
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        int a = 1, b = 2;
        for (int i = 2; i < n; ++i) {
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};
