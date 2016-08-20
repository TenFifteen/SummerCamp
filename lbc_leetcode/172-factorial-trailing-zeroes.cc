/*
题目大意：
给定一个整数n，求其n！中的尾部的0的数目。要求在log时间内完成

解题思路：
因为0是由5*2得来的。而里面2的数量圆圆多于5，所以只需要计算5的个数就可以了。
然后用n/5表示当前所有5的倍数的数的个数，并且还等于将每个数都缩小5倍，相当于是减去了一个5

遇到的问题：
一次通过。

再次阅读：
这也是一道比较老的题目了。
解法没有问题。
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n){
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
};
/*
第二次做：
经典老题。不过要注意算法背后的原理解释。
*/
class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;

        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
/*
 * old, ok
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n >= 5) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
