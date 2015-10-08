/*
题目：26 % O(1)检测2的幂次 容易

题目大意：
用o1的时间，判断一个int是否是2的幂次

解题思路：
利用n&(n-1)等于减去最后一个二进制的1的性质

遇到的问题：
一开始没有考虑到0
*/
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if (n < 1) return false;
        return (n & (n-1)) == 0;
    }
};
