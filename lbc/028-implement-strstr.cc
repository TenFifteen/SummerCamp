/*
题目大意：
给一个字符串，一个模式串，找出模式串在字符串中第一次出现的位置；没有则返回-1；

解题思路：
应该是用KMP解这种题目的。可是为啥最简单的方法就过了。

遇到的问题：
一定要记得容器size返回的是unsigned。
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())return -1;
        for(int i = 0; i < haystack.size()-needle.size()+1; ++i){
            bool found = true;
            for(int j = i; j < i+needle.size(); ++j){
                if(haystack[j] != needle[j-i]){
                    found = false;
                    break;
                }
            }
            if(found)return i;
        }
        return -1;
    }
};