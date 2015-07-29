/*
题目大意：
给定一个整数，判断这个整数的各个数字所组成的字符串是否是回文。要求不能使用额外空间。

解题思路：
不适用额外空间，理解为不能将整数转化为字符串。
然后如果是负数的话，直接就是false。
先计算出整数的长度；
然后对于长度的一半（需要考虑一下奇偶），分别判断整数的首尾是否相等，
如果不相等则直接返回false

遇到的问题：
这个题目竟然一次通过，感觉还可以。
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        int len = 0;
        int tmp = x;
        while(tmp){
            len ++;
            tmp /= 10;
        }
        tmp = 1;
        for(int i = 1; i < len; ++i){
            tmp *= 10;
        }
        for(int i = 0; i < len/2; ++i){
            int head = x / tmp;
            int tail = x % 10;
            x %= tmp;
            x /= 10;
            tmp /= 100;
            if(head != tail){
                return false;
            }
        }
        return true;
    }
};