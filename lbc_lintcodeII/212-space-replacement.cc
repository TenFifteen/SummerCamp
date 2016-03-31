/*
题目大意：
给定一个字符串，将其中的空格替换成20%，原地替换。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int len = length;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') len += 2;
        }
        
        int index = len-1;
        for (int i = length-1; i >= 0; --i) {
            if (string[i] == ' ') {
                string[index--] = '0';
                string[index--] = '2';
                string[index--] = '%';
            } else {
                string[index--] = string[i];
            }
        }
        
        return len;
    }
};  