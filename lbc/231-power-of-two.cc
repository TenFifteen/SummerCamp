/*
题目大意：
给一个整数n。问其是否为2的某个幂次方。

解题思路：
直接遍历所有的可能。

遇到的问题：
一开始将边界设成了32.然后就溢出了。。
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