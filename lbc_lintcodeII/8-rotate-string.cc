/*
题目大意：
给定一个字符串，将其向右移动offset。

解题思路：
翻转url的思路

遇到的问题：
没有。
*/
class Solution {
    void reverse(string &str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }
    
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if (str.size() == 0) return;
        
        offset %= str.size();
        if (offset == 0) return;
        
        int n = str.size();
        reverse(str, 0, n-1);
        reverse(str, 0, offset-1);
        reverse(str, offset, n-1);
    }
};
