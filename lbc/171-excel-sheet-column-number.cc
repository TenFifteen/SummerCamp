/*
题目大意：
给定一个excel的编号，求其对应的整数。

解题思路：
相当于是26进制，转化为十进制。

遇到的问题：
一次通过。
*/
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(auto ch:s){
            ret *= 26;
            ret += ch-'A'+1;
        }
        return ret;
    }
};