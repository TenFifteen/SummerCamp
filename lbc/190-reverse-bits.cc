/*
题目大意：
给定一个无符号整数，将其所有位翻转

解题思路：
从后往前扫描一遍

遇到的问题：
题目说是32位整数，但是网上有人说，长度不一定。

再次阅读：
首先这道题用位操作是没有问题的，感觉之前的做法问题也不大。
但是在DISCUSS中竟然看到了一个利用上了之前ICS里面的技巧，实在是有点厉害呀：
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(uint32_t i = 1; i != 0; i <<= 1){
            ret <<= 1;
            ret += i & n ? 1 : 0;
        }
        return ret;
    }
};