/*
题目大意：
给定两个int，问将其中一个转化为另一个，需要改变多少个bit

解题思路：
异或。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c = a^b;
        int cnt = 0;
        while (c) {
            cnt++;
            c &= c-1;
        }
        return cnt;
    }
};