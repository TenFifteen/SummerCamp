/*
题目大意：
给定一个正整数，然后如果其大于一位数，则将各位数字加起来。如果加完了还是大于一位数，则继续。
直到为一位数为止。

解题思路：
这个东西竟然叫做digital root。中文叫数根。
有一个标准的公式。
dr(n) = 0 if n == 0
dr(n) = (b-1) if n != 0 and n % (b-1) == 0
dr(n) = n mod (b-1) if n % (b-1) != 0

简化后就是：
dr(n) = 1 + (n - 1) % 9

遇到的问题：
虽然是知道了答案，但是并不知道为什么。

再次阅读：
不知道这个公式，现在还是不知道。
*/
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num-1) % 9;
    }
};
/*
第二次做：
这次是看了提示之后，自己找到的规律。
*/
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};
/*
 * still hard. but we can list all the answers to find the law.
 */
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num-1) % 9;
    }
};
