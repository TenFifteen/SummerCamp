/*
题目：41 % 硬币排成线 中等

题目大意：
给定一串硬币，两个人分别取。每次可以去一个或者两个。最后哪个人没有硬币取了就算输了。
问给定一个n， 判断先手赢还是输

解题思路：
只要是3的整数倍，先手输。

遇到的问题：
没有问题。
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
