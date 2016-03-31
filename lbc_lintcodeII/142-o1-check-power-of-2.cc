/*
题目大意：
给定一个整数，判断其是否是2的某次方。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if (n <= 0) return false;
        return !(n & (n-1));
    }
};