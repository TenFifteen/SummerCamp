/*
题目大意：
给一个整数n。问其是否为2的某个幂次方。

解题思路：
直接遍历所有的可能。

遇到的问题：
一开始将边界设成了32.然后就溢出了。。

再次阅读：
一看之前的实现就知道不是最优的，明明是可以检查是否只含有一个1来完成的：
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }
};
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i < 31; ++i){
            if(n == 1<<i)return true;
        }
        return false;
    }
};
/*
第二次做：
简单题，做的不错。
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return (n & (n-1)) == 0;
    }
};
/*
 * good
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return (n & (n - 1)) == 0;
    }
};
