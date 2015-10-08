/*
题目：旋转字符串 容易

题目大意：
将字符串向右移动指定个字符。循环移动

解题思路：
类似于翻转url的题目

遇到的问题：
一开始竟然将sub函数中的条件忘记了加left
然后就是取模和除法类似，模0是运行时错误
*/
class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // wirte your code here
        if (str.size() == 0) return;
        offset %= str.size();
        if (offset == 0) return;
        sub(str, 0, str.size()-1);
        sub(str, 0, offset-1);
        sub(str, offset, str.size()-1);
    }

    void sub(string &str, int left, int right) {
        for (int i = left; i < left+(right-left+1)/2; ++i){
            swap(str[i], str[right-i+left]);
        }
    }
};

