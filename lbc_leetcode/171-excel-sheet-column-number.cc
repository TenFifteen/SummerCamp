/*
题目大意：
给定一个excel的编号，求其对应的整数。

解题思路：
相当于是26进制，转化为十进制。

遇到的问题：
一次通过。

再次阅读：
比较简单。
*/
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(auto ch:s){
            ret *= 26;
            ret += ch-'A'+1;
        }
        return ret;
    }
};
/*
第二次做：
简单题，但是我还是尝试了两次。。。
看来今天做的是有点累了哈。
*/
class Solution {
public:
    int titleToNumber(string s) {
        if (s.size() == 0) return 0;
        
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans *= 26;
            ans += s[i]-'A'+1;
        }
        return ans;
    }
};