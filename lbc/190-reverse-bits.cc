/*
题目大意：
给定一个无符号整数，将其所有位翻转

解题思路：
从后往前扫描一遍

遇到的问题：
题目说是32位整数，但是网上有人说，长度不一定。
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