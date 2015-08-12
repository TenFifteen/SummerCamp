/*
题目大意：
给定一个无符号整数，求其中为1的位的个数

解题思路：
利用n & -n获得最后一个为1的bit

遇到的问题：
没有问题，一次通过
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            ret++;
            n -= n & -n;
        }
        return ret;
    }
};