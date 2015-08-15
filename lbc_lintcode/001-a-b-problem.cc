/*
题目：A + B 问题 中等

题目大意：
不用加法实现加法

解题思路：
用位运算

遇到的问题：
总感觉自己实现的有点啰嗦
不过还是一次通过了

优秀代码：
http://www.bubuko.com/infodetail-553698.html
其第二种解法甚妙
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
        bool surplus = false;
        int ans = 0;
        for (int i = 1; i != 0; i <<= 1) {
            ans |= (i & a) ^ (i & b) ^ (surplus? i:0);
            surplus = (i & a & b) || (i & a && surplus) || (i & b && surplus);
        }
        return ans;
    }
};
