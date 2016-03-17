/*
题目大意：
给定一个字符串和一个模式串，其中模式串中?代表任意一个字符；
*代表0-n个任意字符。问字符串和模式串是否是匹配的。

解题思路：
本来应该用动归的。
不过想着还有一个比动归可能好点的方式，就是之前在leetcode中看到的。
就在这试了一下。

遇到的问题：
要注意while的结束条件，还有就是判断star是不是NULL。
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        const char *star = NULL, *last;
        
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            } else if (*p == '*') {
                star = p++;
                last = s;
            } else {
                if (star == NULL) return false;
                s = ++last;
                p = star+1;
            }
        }
        
        while (*p == '*') p++;
        
        return *s == 0 && *p == 0;
    }
};