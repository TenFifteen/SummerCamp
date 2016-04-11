/*
题目大意：
给定一个字符串，问其中所有的字母是不是只有一个。

解题思路：
可以用hash或者sort，而且，可以先判断是否是大于了256

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        // sort or hash, I use sort to implement
        sort(str.begin(), str.end());
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == str[i-1]) return false;
        }
        return true;
    }
};