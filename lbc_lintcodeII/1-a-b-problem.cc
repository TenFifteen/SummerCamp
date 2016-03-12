/*
题目大意：
给定两个int，问不用加法操作来实现加法。

解题思路：
用异或和and来实现

遇到的问题：
没有。
*/
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        if (a & b) {
            return aplusb(a^b, (a&b)<<1);
        }
        return a^b;
    }
};