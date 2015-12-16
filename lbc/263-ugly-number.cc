/*
题目大意：
给定一个数字，判断其是否为丑数。
丑数的定义是首先是一个正数，然后1也是丑数。
然后就是丑数只包含2、3、5这三个素数因子。

解题思路：
直接按照定义进行求解就行。

遇到的问题：
没有问题。
*/
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        
        return num == 1;
    }
};