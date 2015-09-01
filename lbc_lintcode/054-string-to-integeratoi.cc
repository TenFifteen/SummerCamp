/*
题目：15 % 转换字符串到整数 困难

题目大意：
实现atoi函数

解题思路：
首先要去掉前导0
然后考虑正负号
然后就是一个一个的往后处理，一旦遇到了非法字符，就直接返回当前结果。
还需要判断溢出的情况

遇到的问题：
一开始没考虑到前导0
*/
class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        int ans = 0;
        if (str == "") return ans;
        int index = 0;
        bool neg = false;
        
        //tackle head zeros
        while (index < str.size() && str[index] == ' ') index++;
        
        if (str[index] != '-' && str[index] != '+' && (str[index] < '0' || str[index] > '9')) return ans;
        if (str[index] == '+') {
            index++;
        } else if (str[index] == '-') {
            index++;
            neg = true;
        }
        
        for (int i = index; i < str.size(); ++i) {
            if (str[i] < '0' || str[i] > '9') {
                return ans;
            }
            
            int newval = ans * 10;
            if (neg) {
                newval -= str[i] - '0';
                if (newval > ans) return INT_MIN;
                ans = newval;
            } else {
                newval += str[i] - '0';
                if (newval < ans) return INT_MAX;
                ans = newval;
            }
        }
        return ans;
    }
};
