/*
题目大意：
给定一排硬币，每个人一次只能拿1-2个。两个人轮流拿，问第一个人是否能赢？

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        return n % 3;
    }
};