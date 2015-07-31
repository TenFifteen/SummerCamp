/*
题目大意：
给定一个字符串，判定其是否是一个回文的。只考虑字母和数字。忽略大小写。

解题思路：
将字符串先转化为一个纯净的字符串，然后进行首尾比较。

遇到的问题：
其实也可以不用单独再开辟sp空间，可以用两个指针不断的移动。
一开始差点当做了动态规划做的最长回文子串问题了。
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string ps;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] <= 'z' && s[i] >= 'a'){
                ps.push_back(s[i]);
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                ps.push_back(s[i]-'A'+'a');
            }else if(s[i] >= '0' && s[i] <= '9'){
                ps.push_back(s[i]);
            }
        }
        if(ps == "")return true;
        for(int i = 0; i < ps.size()/2; ++i){
            if(ps[i] != ps[ps.size()-1-i])return false;
        }
        return true;
    }
};