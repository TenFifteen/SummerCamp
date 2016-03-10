/*
题目大意：
给定一个字符串表示的数字，问是否是有效的数字。

解题思路：
按照数字的正则表达式进行求解。

遇到的问题：
没有问题，我竟然可以手写该代码啦。。。
*/
class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int len = 0;
        for (auto ch : s) {
            if (ch != ' ') s[len++] = ch;
        }
        
        if (len == 0) return false;
        
        int index = 0;
        if (s[index] == '+' || s[index] == '-') index++;
        
        int dot = 0, digit = 0;
        while (index < len && (s[index] == '.' || s[index] >= '0' && s[index] <= '9')) {
            if (s[index] == '.') dot++;
            else digit++;
            index++;
        }
        if (dot > 1 || digit == 0) return false;
        
        
        if (index < len) {
            if (s[index] == 'e' || s[index] == 'E') index++;
            else return false;
            
            if (index < len && (s[index] == '+' || s[index] == '-')) index++;
            if (index >= len) return false;
            
            while (index < len && (s[index] <= '9' && s[index] >= '0')) index++;
            return index == len;
        }
        
        return true;
    }
};