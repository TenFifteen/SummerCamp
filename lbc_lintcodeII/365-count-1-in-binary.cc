/*
题目大意：
给定一个int，问其中有多少个1的bit

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int cnt = 0;
        while (num) {
            cnt++;
            num &= num-1;
        }
        return cnt;
    }
};