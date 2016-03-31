/*
题目大意：
判断一个数字是不是丑数。

解题思路：
见代码。

遇到的问题：
一开始当做了计算第n个丑数了。。
*/
class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if (num < 1) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        
        return num == 1;
    }
};