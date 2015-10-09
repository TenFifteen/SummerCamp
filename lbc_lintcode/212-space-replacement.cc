/*
题目：15 % 空格替换 容易

题目大意：
给定一个字符串，将其中的空格替换成20%

解题思路：
从后往前放，就可以进行原地的替换了。

遇到的问题：
没有问题。
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
        int blanks = 0;
        for(int i = 0; i < length; ++i){
            if(string[i] == ' '){
                blanks++;
            }
        }
        int newlen = length + 2*blanks;
        int ret = newlen;
        for(int i = length-1; i >= 0; --i){
            if(string[i] == ' '){
                string[--newlen] = '0';
                string[--newlen] = '2';
                string[--newlen] = '%';
            }else{
                string[--newlen] = string[i];
            }
        }
        return ret;
    }
};  
